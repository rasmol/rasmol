%{

#ifdef __cplusplus

extern "C" {

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __GNUC__
#ifdef USEMALLOCH
#include <malloc.h>
#endif
#endif

#include "rasmol.h"

#ifdef IBMPC
#include <windows.h>
#include <malloc.h>
#endif
#ifdef APPLEMAC
#include <Types.h>
#endif
#ifndef sun386
#include <stdlib.h>
#endif


#include "cif.h"

#ifdef malloc
#undef malloc
#endif
#define malloc(x) _fmalloc(x)

#ifdef free
#undef free
#endif
#define free(x)  FreeAlloc(x)

#define yyparse       cif_parse
#define yylex         cif_lex_wrapper
#define yyerror       cif_syntax_error
#define yyoverflow(msg,u,v,w,x,y)  RasMolFatalExit(msg)

#define YYLEX_PARAM   context
#define YYPARSE_PARAM context

int cif_lex (void *, void *);

int cif_lex_wrapper (void *val, void *context)
{
  int token;

  do

    token = cif_lex (val, ((void **) context) [0]);

  while (token == COMMENT);

  return token;
}

int cif_syntax_error ( char *message)
{
  WriteString (message);
  WriteChar ('\n');
  return 0;
}

%}

%union
{
  int          errorcode;
  const char  *text;
  cif_node    *node;
}

%token <text> DATA
%token        LOOP
%token <text> ITEM
%token <text> CATEGORY
%token <text> COLUMN
%token <text> STRING
%token <text> CIFWORD
%token <text> BINARY
%token <text> UNKNOWN
%token <text> COMMENT
%token <errorcode> ERROR

%type  <node> cbf
%type  <node> cbfstart
%type  <node> datablockstart
%type  <node> datablock
%type  <node> category
%type  <node> column
%type  <node> assignment
%type  <node> loopstart
%type  <node> loopcategory
%type  <node> loopcolumn
%type  <node> loopassignment
%type  <text> datablockname
%type  <text> categoryname
%type  <text> columnname
%type  <text> itemname
%type  <text> value

%pure_parser
%no_lines
%expect 0

%%

cbf:              datablock                     {
                                                  cif_failnez (cif_find_parent (&($$), $1, CIF_ROOT))
                                                }
                ;

cbfstart:                                       {
                                                  $$ = ((void **) context) [1];
                                                }
                ;

datablockstart:   cbfstart                      {
                                                  cif_failnez (cif_make_child (&($$), $1, CIF_DATABLOCK, NULL))
                                                }
                | cbf datablockname             {
                                                  cif_failnez (cif_make_child (&($$), $1, CIF_DATABLOCK, $2))
                                                }
                ;

datablock:        datablockstart                {
                                                  $$ = $1;
                                                }
                | assignment                    {
                                                  cif_failnez (cif_find_parent (&($$), $1, CIF_DATABLOCK))
                                                }
                | loopassignment                {
                                                  cif_failnez (cif_find_parent (&($$), $1, CIF_DATABLOCK))
                                                }
                ;

category:         datablock categoryname        {
                                                  cif_failnez (cif_make_child (&($$), $1, CIF_CATEGORY, $2))
                                                }
                ;

column:           category columnname           {
                                                  cif_failnez (cif_make_child (&($$), $1, CIF_COLUMN, $2))
                                                }
                | datablock itemname            {
                                                  cif_failnez (cif_make_new_child (&($$), $1, CIF_CATEGORY, NULL))
                                                  
                                                  cif_failnez (cif_make_child (&($$), $$, CIF_COLUMN, $2))
                                                }
                ;

assignment:       column value                  {
                                                  $$ = $1;

                                                  cif_failnez (cif_set_columnrow ($$, 0, $2))
                                                }
                ;

loopstart:        datablock loop                {
                                                  cif_failnez (cif_make_node (&($$), CIF_LINK,  NULL))

                                                  cif_failnez (cif_set_link ($$, $1))
                                                }
                ;

loopcategory:     loopstart categoryname        {
                                                  cif_failnez (cif_make_child (&($$), $1, CIF_CATEGORY, $2))

                                                  cif_failnez (cif_set_link ($1, $$))

                                                  $$ = $1;
                                                }
                | loopcolumn categoryname       {
                                                  cif_failnez (cif_find_parent (&($$), $1, CIF_DATABLOCK))

                                                  cif_failnez (cif_make_child (&($$), $$, CIF_CATEGORY, $2))

                                                  cif_failnez (cif_set_link ($1, $$))

                                                  $$ = $1;
                                                }
                ;

loopcolumn:       loopstart itemname            {
                                                  cif_failnez (cif_make_new_child (&($$), $1, CIF_CATEGORY, NULL))
                                                  
                                                  cif_failnez (cif_make_child (&($$), $$, CIF_COLUMN, $2))

                                                  cif_failnez (cif_set_link ($1, $$))

                                                  cif_failnez (cif_add_link ($1, $$))

                                                  $$ = $1;
                                                }
                | loopcolumn itemname           {
                                                  cif_failnez (cif_find_parent (&($$), $1, CIF_DATABLOCK))

                                                  cif_failnez (cif_make_child (&($$), $$, CIF_CATEGORY, NULL))
                                                  
                                                  cif_failnez (cif_make_child (&($$), $$, CIF_COLUMN, $2))

                                                  cif_failnez (cif_set_link ($1, $$))

                                                  cif_failnez (cif_add_link ($1, $$))

                                                  $$ = $1;
                                                }
                | loopcategory columnname       {
                                                  cif_failnez (cif_make_child (&($$), $1, CIF_COLUMN, $2))

                                                  cif_failnez (cif_set_link ($1, $$))

                                                  cif_failnez (cif_add_link ($1, $$))

                                                  $$ = $1;
                                                }
                ;

loopassignment:   loopcolumn value              {
                                                  $$ = $1;

                                                  cif_failnez (cif_shift_link ($$))

                                                  cif_failnez (cif_add_columnrow ($$, $2))
                                                }
                | loopassignment value          {
                                                  $$ = $1;

                                                  cif_failnez (cif_shift_link ($$))

                                                  cif_failnez (cif_add_columnrow ($$, $2))
                                                }
                ;
                
loop:             LOOP
                ;

datablockname:    DATA                          {
                                                  $$ = $1;
                                                }
                ;

categoryname:     CATEGORY                      {
                                                  $$ = $1;
                                                }
                ;

columnname:       COLUMN                        {
                                                  $$ = $1;
                                                }
                ;
                
itemname:         ITEM                          {
                                                  $$ = $1;
                                                }
                ;

value:            STRING                        {
                                                  $$ = $1;
                                                }
                | CIFWORD                          {
                                                  $$ = $1;
                                                }
                | BINARY                        {
                                                  $$ = $1;
                                                }
                ;

%%

#ifdef __cplusplus

}

#endif

