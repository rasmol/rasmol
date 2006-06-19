/* prepdoc.c
 * Document Preparation System
 * Roger Sayle, Version 1.1, January 1994
 * Version 1.3
 * Herbert J. Bernstein, June 1999, rev Feb 2005
 */

/* #define APPLEMAC */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#ifdef APPLEMAC
#include <console.h>
#endif


#ifndef True
#define True  1
#define False 0
#endif

#define RTFForm     0x00
#define LaTeXForm   0x01
#define HTMLForm    0x02
#define TextForm    0x03
#define HelpForm    0x04
#define ManForm     0x05
#define VaxForm     0x06

#define StrTabLen   32768
#define StrPtrTabLen 1024

static char StrTab[StrTabLen];
static char* StrPtrTab[StrPtrTabLen];
static size_t StrLenTab[StrPtrTabLen];
static int NumStr;
static int NumStrChr;
static int NumSec;
static int StrSecTab[StrPtrTabLen];

static int Pass;
static int LineNum;


static char Buffer[514];
static char BodyBlock[255] = "<body>";
static int nblen;
static FILE *OutFile;
static FILE *InFile;
static int SplitFlag;
static int Format;

int strncasecmp(const char *str1, const char *str2, size_t n);


static void StrInit()
{
    register int i;
    
    NumStr = 0;
    NumStrChr = 0;
    NumSec = 0;
    for (i=0; i< StrTabLen; i++) StrTab[i] = 0;
    for (i=0; i< StrPtrTabLen; i++)
    {  StrPtrTab[i] = 0;
       StrLenTab[i] = 0;
       StrSecTab[i] = 0;
    }
}

static int StrPtr ( char *str )
{   size_t len;
    int i;
    char *ptr;

    len = strlen(str);
    for (i=0; i<StrPtrTabLen; i++)
    {  if (len == StrLenTab[i] ) {
         if ( !strncmp(str,StrPtrTab[i],len) ) return i;
       }    
    }
    ptr = strstr(StrTab,str);
    if (ptr)
    { if (NumStr < StrPtrTabLen)
      {  StrPtrTab[NumStr] = ptr;
         StrSecTab[NumStr] = NumSec;
         StrLenTab[NumStr++] = len;
         return -NumStr;
      } else {
        fprintf(stderr,"String Pointer Table overflow.  Line %d\n",
          LineNum);
        exit (1);
      }
     } else {
       if (NumStrChr+len < StrTabLen)
       { for (i=0; i<len; i++) StrTab[NumStrChr+i]=str[i];
         ptr = &StrTab[NumStrChr];
         NumStrChr += len;
         if (NumStr < StrPtrTabLen)
         {  StrPtrTab[NumStr] = ptr;
            StrSecTab[NumStr] = NumSec;
            StrLenTab[NumStr++] = len;
            return -NumStr;
         } else {
           fprintf(stderr,"String Pointer Table overflow.  Line %d\n", 
             LineNum);
           exit (1);
         }         
       } else {
        fprintf(stderr,"String Character Table overflow.  Line %d\n",
          LineNum);
        exit (1);
       }
     }

}


static int ReadLine()
{
    register char *ptr;
    register int len;
    register int ch;

    if( feof(InFile) )
    {   *Buffer = 0;
        return( False );
    }

    LineNum++;
    ptr = Buffer;
    nblen = 0;
    do {
        ch = getc(InFile);
        if( (ch=='\n') || (ch=='\r') )
        {   while( ptr != Buffer )
                if( *(ptr-1)!=' ' )
                {   *ptr = 0;
                    nblen = ptr-Buffer;
                    return( True );
                } else ptr--;
        } else if( ch==EOF )
        {   *ptr = 0;
             nblen = ptr-Buffer;
            return( True );
        } else *ptr++ = ch;
    } while( ptr < Buffer+512 );
    *ptr = 0;
    nblen = ptr-Buffer;

    /* skip to the end of the line! */
    do { ch = getc(InFile);
    } while( (ch!='\n') && (ch!='\r') && (ch!=EOF) );
    return( True );
}


static int TextFlag;
static int TextCol;

static void DisplayLowerCase( ptr )
    char *ptr;
{
    register char ch;

    while( (ch = *ptr++) )
        if( isupper(ch) )
        {   putc(tolower(ch),OutFile);
        } else putc(ch,OutFile);
}


static void ConvLowerCase (char *dst, char *ptr)
{
    register char ch;
    
    while( (ch = *ptr++) )
        if( isupper(ch) )
        {   *dst++ = tolower(ch);
        } else if( ch != ' ' )
            *dst++ = ch;
    strcpy(dst,".html");
    return;
}


static void OpenLowerCase( ptr )
    char *ptr;
{
    register char *dst;
    register char ch;
    char buffer[256];

    fputs("\n<p>\n",OutFile);
    if( OutFile != stdout )
        fclose(OutFile);

    ConvLowerCase(buffer,ptr);

    if( !(OutFile = fopen(buffer,"w")) )
    {   fprintf(stderr,"Warning: Unable to create file `%s'!, Line %d\n",
          buffer, LineNum);
        OutFile = stdout;
    }
}


static void DisplayOnlyLowerCase( ptr )
    char *ptr;
{
    register char ch;
    
    while( (ch = *ptr++) )
        if( isupper(ch) )
        {   putc(tolower(ch),OutFile);
        } else if( (ch >= 'a' && ch <= 'z') || (ch >='0' && ch <= '9') )
            putc(ch,OutFile);
}
    

static void DisplayText( src )
    char *src;
{
    register char *ptr;
    register char *dst;
    register int max;

    max = (Format==VaxForm)? 68 : 76;

    while( *src )
    {   dst = src;
        while( *dst && *dst!=' ' )
            dst++;

        if( TextCol+(dst-src) > max )
        {   putc('\n',OutFile);
            TextCol = 0;
        }

        if( !TextCol && (Format==VaxForm) )
            putc(' ',OutFile);

        while( src != dst )
        {   putc( *src++, OutFile );
            TextCol++;
        }

        while( *src==' ' )
            src++;
        putc(' ',OutFile);
        TextCol++;
    }
}

static char *VAXSection( ptr )
    char *ptr;
{
    register char *tmp;

    if( !strncmp(ptr,"Set ",4) )
        ptr += 4;

    for( tmp=ptr; *tmp; tmp++ )
        if( *tmp==' ' )
            *tmp = '_';
    return( ptr );
}


static void SplitRawHTML( ptr )
    char *ptr;
{
    register char *src;
    register char *dst;
    register int flag;
    register int iptr;
    char buffer[80];
    char secname[80];

    while( *ptr )
    {   flag = True;
        if( *ptr == '<' )
        {   if( ptr[1]=='a' || ptr[1]=='A')
            {   if( !strncasecmp(ptr,"<a href=\"#",10) )
                {   dst = buffer;
                    for( src = ptr+10; *src && (*src!='"'); src++ )
                        *dst++ = *src;
                    *dst = '\0';
                    if ( ( iptr=StrPtr(dst) ) < 0 )
                    {  fprintf(stderr,"Missing Tag \"%s\", Section %d, Line %d\n",
                         dst,NumSec, LineNum);
                       fprintf(OutFile,"<a name=\"%s\"></a>",dst);
                       iptr= (-iptr-1);
                    }
                    fputs("<a href=\"",OutFile);
                    sprintf(secname,"sect%d",StrSecTab[iptr]);
                    ConvLowerCase(secname,secname);
                    fputs(secname,OutFile);
                    ptr += 9;
                    flag = False;
                } 
            } else {
                 if( (ptr[1]=='b' || ptr[1]=='B') && !strncasecmp(ptr,"<body ",6))
                 {   dst = BodyBlock;
                     while (*ptr && *ptr != '>') *dst++ = *ptr++;
                     if (*ptr == '>') {
                     putc(*ptr,OutFile);
                     ptr++;
                     }
                     *dst = 0;
                     flag = False;
                 } 
	    }
        }
        if (flag)
	{
            putc(*ptr,OutFile);
            ptr++;
        }
    }

    /* EndOfLine Char */
    putc('\n',OutFile);
}

static void FilterHTMLChar( ptr )
    char **ptr;
{
    char ch;
    
    ch = **ptr;
    if ( !ch ) return;
    (*ptr)++;
    if( ch == '&' )
    {   fprintf(OutFile,"&amp;");
    } else {
      if( ch == '<' )
      {   fprintf(OutFile,"&lt;");
      } else {
        if( ch == '>' )
        {   fprintf(OutFile,"&gt;");
        } else {
          if( ch == '"' )
          {   fprintf(OutFile,"&quot;");
          } else {
            if( ch == 'A' && !strncmp(*ptr,"ngstrom",7) )
            {   fprintf(OutFile,"&Aring;ngstrom");
                *ptr += 7;
            } else {
              if ( ch == 'i' && !strncmp(*ptr,".e.",3) )
              {   fprintf(OutFile,"<i>i.e.</i>");
                  *ptr += 3;
              } else {
                if ( ch == 'e' && !strncmp(*ptr,"g.",3) )
                {   fprintf(OutFile,"<i>e.g.</i>");
                *ptr += 3;
                } else {
                  putc(ch,OutFile);
                }
              }
            }
          }
        }
      }
    }
}


static void OnlyLowerCase( char *ptrlow, char *ptruplow )
{
    register char ch;
    
    while( (ch = *ptruplow++) )
        if( isupper(ch) )
        {   *ptrlow++ = tolower(ch);
        } else if( (ch >= 'a' && ch <= 'z') || (ch >='0' && ch <= '9') || ch == '_' )
            *ptrlow++ = ch;
    *ptrlow = 0;
    return;
}

static void ProcHTag()
{
    static char buffer[80];
    static char *ptr;
    register int i,len;
    register char echar;

    ptr = Buffer+2;
    OnlyLowerCase(buffer,ptr);
    if (StrPtr(buffer) >= 0) 
      fprintf(stderr,"Duplicate section tag \"%s\", Section %d, Line %d\n",
        ptr,NumSec, LineNum);
    return;
}


static void ProcRawHTag( )
{
    register char *ptr;
    register char *src;
    register char *dst;
    static char buffer[80];
    static char bufferlow[80];

    ptr = Buffer+2;
    while( *ptr )
        if( *ptr == '<' )
        {   if( ptr[1]=='a' || ptr[1]=='A')
            {   /* Anchor Format Problems? */
                if( !strncasecmp(ptr,"<a name=\"",9) )
                {   dst = buffer;
                    for( src = ptr+9; *src && (*src!='"'); src++ )
                        *dst++ = *src;
                    *dst = '\0';
                    OnlyLowerCase(bufferlow,buffer);
                    if (StrPtr(bufferlow) >= 0) 
                     fprintf(stderr,"Duplicate section tag \"%s\", Section %d, Line %d\n",
                       buffer,NumSec, LineNum);
                    if( *src )
                    {   ptr = src+1;
                        while( *ptr && (*ptr!='>') )
                            ptr++; 
                        if( *ptr ) ptr++;
                    } else ptr = src;
                } else if( !strncasecmp(ptr,"<a href=\"#",10) )
                {   for( ptr+=10; *ptr && (*ptr!='"'); ptr++ );
                    ptr++;
                } else /* Unrecognised anchor */
                {  ptr++;
                }
            } else if( (ptr[1]=='/') && (ptr[2]=='a') && (ptr[3]=='>') )
            {   ptr += 4;
            } else /* Unrecognised code */
            {   ptr++;
            }
        } else  /* Normal Character! */
        {   ptr++;
        }
}


static void ProcessCommand()
{
    static char buffer[80];
    static char secname[80];
    static char *ptr;
    register int i,len,iptr;
    register char echar;

    ptr = Buffer+2;
    switch( Buffer[1] )
    {   /* mR: Raw format text -- formatting in the text stream */
	    case('R'):  if( TextCol )
                        putc('\n',OutFile);
                    if( SplitFlag )
                    {   SplitRawHTML(ptr);
                    } else fprintf(OutFile,"%s\n",ptr);
                    TextFlag = True;
                    TextCol = 0;
                    break;
					
        /* mT: Plain text */
        case('T'):  if( Format == RTFForm )
                    {   fprintf(OutFile,"%s {}\n",ptr);
                        TextCol = 0;
                    } else if( Format == HTMLForm )
                    {   while( *ptr )
                            FilterHTMLChar(&ptr);
                        putc('\n',OutFile);
                        TextCol = 0;
                    } else if( (Format!=TextForm) &&
                               (Format!=HelpForm) &&
                               (Format!=VaxForm) )
                    {   fprintf(OutFile,"%s\n",ptr);
                        TextCol = 0;
                    } else DisplayText(ptr);
                    TextFlag = True;
                    break;
					
					
		/* mQ:  Fixed font text (equivalent to HTML <tt>) */			
		case('Q'):   if( Format == RTFForm )
                    {   fprintf(OutFile,"\\pard{\\f2 \\fs20");
						while (*ptr) {
						  if (*ptr == ' ') {
                                                    putc('\\',OutFile);
                                                    putc('~',OutFile);
                                                    ptr++;
                                                  } else {
						    putc(*ptr++,OutFile);
                                                  }
						}
						fprintf(OutFile,"\\par}\n");
                        TextCol = 0;
                    } else if( Format == HTMLForm )
                    {   fprintf(OutFile, "<tt>");
					    while( *ptr ) {
						    if (*ptr == ' ') {
							  fprintf(OutFile, "&nbsp;");
							  ptr++;
							} else {
                              FilterHTMLChar(&ptr);
							}
						}
					    fprintf(OutFile, "</tt><br/>");
                        putc('\n',OutFile);
                        TextCol = 0;
                    } else if( (Format!=TextForm) &&
                               (Format!=HelpForm) &&
                               (Format!=VaxForm) )
                    {   fprintf(OutFile,"%s\n",ptr);
                        TextCol = 0;
                    } else DisplayText(ptr);
                    TextFlag = True;
                    break;

        /* mP: Paragraph break */
        case('P'):  if( TextFlag )
                    {   if( Format == HTMLForm )
                        {   fputs("<p>\n",OutFile);
                        } else if( Format==RTFForm )
                        {   fputs("\\par\\par\n",OutFile);
                        } else if( (Format==TextForm) || 
                                   (Format==HelpForm) ||
                                   (Format==VaxForm) )
                        {   fputs("\n\n",OutFile);
                        } else putc('\n',OutFile);
                        TextFlag = False;
                        TextCol = 0;
                    }
                    break;
					
        /* mB: Section break */
        case('B'):  if( TextFlag )
                    {   if( Format==HTMLForm )
                        {   if( !SplitFlag )
                            {   fputs("<p><hr>\n",OutFile);
                            } else {
                                fputs("<p><hr><center>",OutFile);
                                if(NumSec>0) {
                                  sprintf(buffer,"sect%d",NumSec-1);
                                  ConvLowerCase(buffer,buffer);
                                  fprintf(OutFile,"<a href=\"%s\">&lt; previous</a> | ",buffer);
                                }
                                fprintf(OutFile,"<a href=\"contents.html\">Contents | ");
                                NumSec++;
                                sprintf(buffer,"sect%d",NumSec);
                                ConvLowerCase(buffer,buffer);
                                fprintf(OutFile,"<a href=\"%s\">next &gt;</a>",buffer);
                                fputs("</center>\n</body>\n</html>",OutFile);
                                sprintf(buffer,"sect%d",NumSec);
                                OpenLowerCase(buffer);
                                fprintf(OutFile,
                                  "<html>\n<head>\n<title>%s</title>\n</head>\n%s\n",ptr,BodyBlock);
                            }
                        } else if( Format==RTFForm )
                        {   fputs("\\par\\page\\par\n",OutFile);
                            fputs("+{\\footnote doc}\n",OutFile);
                        } else if( (Format==TextForm) || 
                                   (Format==HelpForm) ||
                                   (Format==VaxForm) )
                        {   fputs("\n\n",OutFile);
                        } else putc('\n',OutFile);
                        TextFlag = False;
                        TextCol = 0;
                    }
                    break;
					
		/* mS: Section heading */
        case('S'):  if( Format==TextForm )
                    {   len = strlen(ptr);
                        fprintf(OutFile,"%s\n",ptr);
                        for( i=0; i<len; i++ )
                            putc('-',OutFile);
                        fputs("\n\n",OutFile);
                    } else if( Format==HTMLForm )
                    {   if( SplitFlag )
                        {   fputs("<a name=\"",OutFile);
                            DisplayOnlyLowerCase(ptr);
                            fprintf(OutFile,"\"><h1>%s</h1></a><p>\n",ptr);
                        } else
                        {   fputs("<a name=\"",OutFile);
                            DisplayOnlyLowerCase(ptr);
                            fprintf(OutFile,"\"><h3>%s</h3></a><p>\n",ptr);
                        }
                    } else if( Format==RTFForm )
                    {   fputs("#{\\footnote ",OutFile);
                        DisplayOnlyLowerCase(ptr);
                        fprintf(OutFile,"}\n${\\footnote %s}\n",ptr);
                        fputs("K{\\footnote ",OutFile);
                        DisplayLowerCase(ptr);
                        fprintf(OutFile,"}\n{\\b %s}\\par\\par\n",ptr);
                    } else if( Format==HelpForm )
                    {   putc('?',OutFile);
                        DisplayLowerCase(ptr);
                        fprintf(OutFile,"\n%s\n",ptr);
                    } else if( Format==ManForm )
                    {   fprintf(OutFile,".TP\n.B %s\n",ptr);
                    } else if( Format==VaxForm )
                        fprintf(OutFile,"3 %s\n",VAXSection(ptr));

                    TextCol = 0;
                    break;
        /* mX: Section reference (needs a tag) */
        case('X'):  while( *ptr!=' ' )
                        ptr++;
                    *ptr++ = 0;
                    echar = Buffer[nblen-1];
                    if (echar == '.' || echar == ';' || echar == ',' || echar == ':') 
                    {    Buffer[nblen-1] = 0;
                    } else echar = 0;
                        
                    if( Format == RTFForm )
                    {   fprintf(OutFile,"'{\\uldb %s}",ptr);
                        fprintf(OutFile,"{\\v %s}'",Buffer+2);
                        if (echar) putc(echar,OutFile);
                        fprintf(OutFile," {}\n");
                        break;
                    } else if( Format == HTMLForm )
                    {   if( SplitFlag )
                        { 
                          if ( ( iptr=StrPtr(Buffer+2) ) < 0 )
                          {  fprintf(stderr,"Missing Tag \"%s\", Section %d\n",Buffer+2,NumSec);
                            fprintf(OutFile,"<a name=\"%s\"></a>",Buffer+2);
                            iptr= (-iptr-1);
                          }
                          sprintf(secname,"sect%d",StrSecTab[iptr]);
                          ConvLowerCase(secname,secname);
                          fprintf(OutFile,"'<a href=\"%s#%s\">",secname,Buffer+2);
                        } else fprintf(OutFile,"'<a href=\"#%s\">",Buffer+2);
                        fprintf(OutFile,"<tt><b>");
                        while( *ptr )
                            FilterHTMLChar(&ptr);
                        if (echar) 
                        { fprintf(OutFile,"</b></tt></a>'%c\n",echar);
                        } else fprintf(OutFile,"</b></tt></a>'\n");
                        break;
                    }
                    if (echar) Buffer[nblen-1] = echar;
                    
	    /* mC: a citation (bolds the text except possibly for a terminal ".", ";", ",' or ":") */
        case('C'):  echar = Buffer[nblen-1];
                    if (echar == '.' || echar == ';' || echar == ',' || echar == ':') 
                    {    Buffer[nblen-1] = 0;
                    } else echar = 0;
                    if( Format == RTFForm )
                    {   if (echar)
                        {
                          if( *ptr=='"' || *ptr=='\'' )
                          {  if(Buffer[nblen-2]==*ptr) Buffer[nblen-2]=0;
                             fprintf(OutFile,"%c{\\f2\\b %s}%c%c {}\n",*ptr, ptr+1, *ptr, echar);
                          } else fprintf(OutFile,"'{\\f2\\b %s}'%c {}\n",ptr, echar);
                        } else {
                          if( *ptr=='"' || *ptr=='\'' )
                          {  if(Buffer[nblen-1]==*ptr) Buffer[nblen-1]=0;
                             fprintf(OutFile,"%c{\\f2\\b %s}%c {}\n",*ptr, ptr+1, *ptr);
                          } else fprintf(OutFile,"'{\\f2\\b %s}' {}\n",ptr);
                        }
                        TextCol = 0;
                    } else if( Format == HTMLForm )
                    {   if( *ptr=='"' || *ptr=='\'')
                        {   int quoted=1;
                            fprintf(OutFile,"&quot;<tt><b>");
                            ptr++;
                            while( *ptr )
			               {
                              if(quoted && (*ptr=='"' || *ptr=='\''))
			                  { fprintf(OutFile,"</b></tt>&quot;");
                                quoted=0;
                                ptr++;
			                  } else {
                                FilterHTMLChar(&ptr);
                              }
                            }
                            if (quoted) 
                            { fprintf(OutFile,"</b></tt>&quot;");
                            }
                            if (echar) putc(echar,OutFile);
                            putc('\n',OutFile);
                        } else {
                          fprintf(OutFile,"'<tt><b>");
                          while( *ptr )
                            FilterHTMLChar(&ptr);
                          if (echar) {
                            fprintf(OutFile,"</b></tt>'%c\n",echar);
                          } else {
                            fprintf(OutFile,"</b></tt>'\n");
                          }
                        }
                    } else if( Format == ManForm )
                    {   if(echar) Buffer[nblen-1] = echar;
                        if( *ptr=='"' || *ptr=='\'') ptr++;
                        if(echar) {
                          if(Buffer[nblen-2]=='"' || Buffer[nblen-2]=='\'') {
                            Buffer[nblen-2] = echar;
                            Buffer[nblen-1] = 0;
                          }
                        } else {
                          if(Buffer[nblen-1]=='"' || Buffer[nblen-1]=='\'') {
                            Buffer[nblen-1] = 0;
                          }
                        }
                        fprintf(OutFile,".B %s\n",ptr);
                    } else if( (Format!=TextForm) &&
                               (Format!=HelpForm) &&
                               (Format!=VaxForm) )
                    {   if( *ptr=='"' || *ptr=='\'') {
                          if(echar) Buffer[nblen-1] = echar; 
                          fprintf(OutFile,"%s\n",ptr);
                        } else {
                          if( *ptr=='*' )
                          {  fprintf(OutFile,"\"%s\"",ptr);
                          } else fprintf(OutFile,"'%s'",ptr);
                          if (echar) putc(echar,OutFile);
                          putc('\n',OutFile);
                        }
                        TextCol = 0;
                    } else /* DisplayText! */
                    {   if( *ptr=='"' || *ptr == '\'' )
                        {  if(echar) Buffer[nblen-1] = echar;
                           sprintf(buffer,"%s",ptr);
                        } else {
                          if(echar) sprintf(buffer,"'%s'%c",ptr,echar);
                          else sprintf(buffer,"'%s'",ptr);
                        }
                        DisplayText(buffer);
                    }
                    TextFlag = True;
                    break;
                    
		/* mK:  Caption text (Bolds the text, except possibly for a terminal ".", ";", "," or ":") 
		        Similar to mC, but used with mP before and after for captions */  
        case('K'):  echar = Buffer[nblen-1];
                    if (echar == '.' || echar == ';' || echar == ',' || echar == ':') 
                    {    Buffer[nblen-1] = 0;
                    } else echar = 0;
                    if( Format == RTFForm )
                    {   if (echar)
                        {
                          if( *ptr=='"' || *ptr=='\'' )
                          {  if(Buffer[nblen-2]==*ptr) Buffer[nblen-2]=0;
                             fprintf(OutFile,"%c{\\f2\\b %s}%c%c {}\n",*ptr, ptr+1, *ptr, echar);
                          } else fprintf(OutFile,"{\\f2\\b %s}%c {}\n",ptr, echar);
                        } else {
                          if( *ptr=='"' || *ptr=='\'' )
                          {  if(Buffer[nblen-1]==*ptr) Buffer[nblen-1]=0;
                             fprintf(OutFile,"%c{\\f2\\b %s}%c {}\n",*ptr, ptr+1, *ptr);
                          } else fprintf(OutFile,"{\\f2\\b %s} {}\n",ptr);
                        }
                        TextCol = 0;
                    } else if( Format == HTMLForm )
                    {   if( *ptr=='"' || *ptr=='\'')
                        {   int quoted=1;
                            fprintf(OutFile,"&quot;<tt><b>");
                            ptr++;
                            while( *ptr )
			               {
                              if(quoted && (*ptr=='"' || *ptr=='\''))
			                  { fprintf(OutFile,"</b></tt>&quot;");
                                quoted=0;
                                ptr++;
			                  } else {
                                FilterHTMLChar(&ptr);
                              }
                            }
                            if (quoted) 
                            { fprintf(OutFile,"</b></tt>&quot;");
                            }
                            if (echar) putc(echar,OutFile);
                            putc('\n',OutFile);
                        } else {
                          fprintf(OutFile,"<tt><b>");
                          while( *ptr )
                            FilterHTMLChar(&ptr);
                          if (echar) {
                            fprintf(OutFile,"</b></tt>%c\n",echar);
                          } else {
                            fprintf(OutFile,"</b></tt>\n");
                          }
                        }
                    } else if( Format == ManForm )
                    {   if(echar) Buffer[nblen-1] = echar;
                        if( *ptr=='"' || *ptr=='\'') ptr++;
                        if(echar) {
                          if(Buffer[nblen-2]=='"' || Buffer[nblen-2]=='\'') {
                            Buffer[nblen-2] = echar;
                            Buffer[nblen-1] = 0;
                          }
                        } else {
                          if(Buffer[nblen-1]=='"' || Buffer[nblen-1]=='\'') {
                            Buffer[nblen-1] = 0;
                          }
                        }
                        fprintf(OutFile,".B %s\n",ptr);
                    } else if( (Format!=TextForm) &&
                               (Format!=HelpForm) &&
                               (Format!=VaxForm) )
                    {   if( *ptr=='"' || *ptr=='\'') {
                          if(echar) Buffer[nblen-1] = echar; 
                          fprintf(OutFile,"%s\n",ptr);
                        } else {
                          if( *ptr=='*' )
                          {  fprintf(OutFile,"\"%s\"",ptr);
                          } else fprintf(OutFile,"'%s'",ptr);
                          if (echar) putc(echar,OutFile);
                          putc('\n',OutFile);
                        }
                        TextCol = 0;
                    } else /* DisplayText! */
                    {   if( *ptr=='"' || *ptr == '\'' )
                        {  if(echar) Buffer[nblen-1] = echar;
                           sprintf(buffer,"\"%s\"",ptr+1);
                        } else {
                          if(echar) sprintf(buffer,"%s%c",ptr,echar);
                          else sprintf(buffer,"%s",ptr);
                        }
                        DisplayText(buffer);
                    }
                    TextFlag = True;
                    break;                    
    }
}


int main( argc, argv )
    int argc;  char *argv[];
{
    register char *fname;
    register char *ptr;
    register int flag;

#ifdef APPLEMAC
    argc = ccommand(&argv);
#endif

    fputs("Document Preparation System\n",stderr);
    fputs("Roger Sayle, Version 1.1, January 1994\n",stderr);
    fputs("Herbert J. Bernstein, Version 1.2, June 1999\n\n",stderr);

    Format = TextForm;
    SplitFlag = False;
    OutFile = stdout;
    StrInit();
    Pass = 0;

    if( argc==2 ) 
    {   fname = argv[1];
    } else if( argc==3 )
    {   fname = argv[2];
        ptr = argv[1];

        if( *ptr=='-' )
            ptr++;

        if( !strcmp(ptr,"latex") )
        {   Format = LaTeXForm;
        } else if( !strcmp(ptr,"help") )
        {   Format = HelpForm;
        } else if( !strcmp(ptr,"html") )
        {   Format = HTMLForm;
        } else if( !strcmp(ptr,"splithtml") )
        {   Format = HTMLForm; SplitFlag = True;
        } else if( !strcmp(ptr,"rtf") || !strcmp(ptr,"mshelp") )
        {   Format = RTFForm;
        } else if( !strcmp(ptr,"text") || !strcmp(ptr,"ascii") )
        {   Format = TextForm;
        } else if( !strcmp(ptr,"man") || !strcmp(ptr,"troff") )
        {   Format = ManForm;
        } else if( !strcmp(ptr,"vax") || !strcmp(ptr,"vms") )
        {   Format = VaxForm;
        } else
        {   fputs("Formats:  -latex  LaTeX .tex file\n",stderr);
            fputs("          -troff  UNIX man(1) pages\n",stderr);
            fputs("          -html   HyperText metalanguage\n",stderr);
            fputs("          -help   RasMol on-line help file\n",stderr);
            fputs("          -rtf    Microsoft Help (Rich Text)\n",stderr);
            fputs("          -text   Standard ASCII text\n\n",stderr);
            fputs("          -vax    VAX VMS Help file\n\n",stderr);
            exit(1);
        }

    } else /* DisplayUsage */
    {   fputs("Usage: prepdoc [format] <filename>\n",stderr);
        exit(1);
    }

    if( !(InFile=fopen(fname,"r")) )
    {   fputs("Error: Unable to open input file!\n",stderr);
        exit(1);
    }

    if (SplitFlag)
    {  rewind(InFile);
       LineNum = 0;
       while( !feof(InFile) )
       {  ReadLine();
          if ( Buffer[0]=='V' ||
               Buffer[0]=='H' ||
               Buffer[0]=='A' ||
               Buffer[0]=='U')
          {  switch( Buffer[1] )
             {
                case('B'):  NumSec++; break;
                case('S'):  ProcHTag(); break;
                case('R'):  ProcRawHTag(); break; 
             }
         
          }
       }
       rewind(InFile);
       NumSec = 0;
    }

    LineNum = 0;
    TextFlag = False;
    TextCol = 0;

    while( !feof(InFile) )
    {   ReadLine();
        switch( *Buffer )
        {   case('V'):  flag = (Format==LaTeXForm) ||
                               (Format==HTMLForm)  ||
                               (Format==RTFForm)   ||
                               (Format==TextForm);   break;
                               
            case('U'):  flag = SplitFlag;            break;

            case('D'):  flag = (Format==TextForm) ||
                               (Format==HelpForm) ||
                               (Format==ManForm);    break;

            case('S'):  flag = (Format==HelpForm) ||
                               (Format==ManForm);    break;

            case('N'):  flag = (Format==TextForm) ||
                               (Format==HelpForm);   break;

            case('L'):  flag = (Format==LaTeXForm);  break;
            case('H'):  flag = (Format==HTMLForm);   break;
            case('P'):  flag = (Format==HelpForm);   break;
            case('T'):  flag = (Format==TextForm);   break;
            case('M'):  flag = (Format==ManForm);    break;
            case('R'):  flag = (Format==RTFForm);    break;
            case('X'):  flag = (Format==VaxForm);    break;
            case('A'):  flag = True;                 break;
            default:    flag = False;
        }

        if( flag )
            ProcessCommand();
    }
    if( OutFile != stdout )
    {   fputs("\n<p>\n",OutFile);
        fclose(OutFile);
    }
    fclose(InFile);
    exit(0);
}

