


};

 
 
void SwitchLang( language lang ) {

  int ii;
  int kmsg;

  kmsg = sizeof(langstrs)/sizeof(langstr);
  for (ii = 0; ii < MaxStrFlag; ii++) {
     MsgStrs[ii] = (char *)0;
     MsgLens[ii] = 0;
     MsgAuxl[ii] = 0;
  }
  for (ii = 0; ii < kmsg; ii++) {
    if (langstrs[ii].lang == lang) {
      MsgStrs[langstrs[ii].msgno] = langstrs[ii].msg;
      MsgLens[langstrs[ii].msgno] = strlen(langstrs[ii].msg);
      MsgAuxl[langstrs[ii].msgno] = langstrs[ii].aux;
    }
  }
  for (ii = 0; ii < kmsg; ii++) {
    if (langstrs[ii].lang == English && !(MsgStrs[langstrs[ii].msgno])) {
      WriteString("\nError: Translation missing for ...\n");
      WriteString(langstrs[ii].msg);
      MsgStrs[langstrs[ii].msgno] = langstrs[ii].msg;
      MsgLens[langstrs[ii].msgno] = strlen(langstrs[ii].msg);
      MsgAuxl[langstrs[ii].msgno] = langstrs[ii].aux;
    }
  }
  Language = lang;
  UpdateLanguage();
  if (Interactive)
    ReDrawWindow();
    if (Language != lang) {
      for (ii = 0; ii < kmsg; ii++) {
        if (langstrs[ii].lang == Language) {
          MsgStrs[langstrs[ii].msgno] = langstrs[ii].msg;
          MsgLens[langstrs[ii].msgno] = strlen(langstrs[ii].msg);
          MsgAuxl[langstrs[ii].msgno] = langstrs[ii].aux;
        }
      }
    ReDrawWindow();
    UpdateLanguage();
    InvalidateCmndLine();
    WriteString("Error: Unable to find font for ");
    WriteString((char *)lang2str(lang));
    WriteString("\n");
    for (ii = 0; ii < NUMLANGS; ii++) {
      if (langfonts[ii].lang == lang) {
        WriteString(langfonts[ii].menufontlist);
        WriteString("\n");
      	
      }
    	
    }
  }

}

language str2lang ( const char * langstr) {

  int ilang;

  for (ilang = 0; ilang < NUMLANGS; ilang++) {
  
    if (!strcasecmp(langstr,langnames[ilang])) {
      return (language) ilang;	
    }
    
  }

  return English;
  	
	
	
}

const char * lang2str ( language lang) {
	
	if ((int)lang >= 0 && (int)lang < NUMLANGS) return langnames[(int)lang];
	else return langnames[0];
}
