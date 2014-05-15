; NSIS Script for RasMol RasWin 2.7.5.2 windows install
; H. J. Bernstein, yaya at bernstein-plus-sons dot com
;

; >>> Include the modern user interface
!include "MUI.nsh"
!include "Sections.nsh"
!include "LogicLib.nsh"

; >>> Name the package, file and default install directory
Name        "RasMol -- RasWin 2.7.5.2"
OutFile     "RasWin_2_7_5_2_Install.exe"
InstallDir  "$PROGRAMFILES\RasWin"
InstallDirRegKey HKLM "Software\RasWin" ""

!define     MUI_ABORTWARNING
!define     MUI_LANGDLL_REGISTRY_ROOT "HKLM" 
!define     MUI_LANGDLL_REGISTRY_KEY "Software\RasWin" 
!define     MUI_LANGDLL_REGISTRY_VALUENAME "Installer Language"
!define     MUI_LANGDLL_ALWAYSSHOW
!define     MUI_COMPONENTSPAGE_SMALLDESC



; >>> insert the bits and pieces we want
!insertmacro MUI_PAGE_LICENSE "..\..\doc\Licenses.txt"
!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
  
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

; >> set up the languages
  
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "French"
!insertmacro MUI_LANGUAGE "German"
!insertmacro MUI_LANGUAGE "Italian"
!insertmacro MUI_LANGUAGE "Spanish"
!insertmacro MUI_LANGUAGE "Russian"
!insertmacro MUI_LANGUAGE "Bulgarian"
!insertmacro MUI_LANGUAGE "SimpChinese"
!insertmacro MUI_LANGUAGE "Japanese"

!insertmacro MUI_RESERVEFILE_LANGDLL


; >>> The actual installer

InstType "Typical"
InstType "Without .scr and .ras extensions"
InstType "Without rasmol.ini"

Section    "Install RasMol -- RasWin 2.7.5.2" SecInstRasWin

SectionIn 1 2 3

SetShellVarContext  all
SetOutPath "$INSTDIR"
File       "..\..\doc\RasMolReferenceCard.pdf"
File       "raswin.exe"
File       "..\..\doc\GPL.txt"
File       "..\..\doc\NOTICE.txt"
File       "..\..\doc\RASLIC.txt"
File       "..\..\doc\rasmol.hlp"
File       "..\..\doc\raswin.hlp"
File       "raswin.ico"
File       "raswin_doc.ico"
File       "raswin_scr.ico"
WriteRegStr SHCTX "Software\RasWin" "" $INSTDIR
WriteUninstaller "$INSTDIR\Uninstall.exe"

WriteRegStr SHCTX \
"Software\Microsoft\Windows\CurrentVersion\Uninstall\RasWin" \
"DisplayName" "RasWin (remove only)"
WriteRegStr SHCTX \
"Software\Microsoft\Windows\CurrentVersion\Uninstall\RasWin" \
"UninstallString" "$INSTDIR\Uninstall.exe"

; >>> start-menu items
SetShellVarContext  all
CreateDirectory    "$SMPROGRAMS\RasWin"
CreateShortCut     "$SMPROGRAMS\RasWin\Uninstall.lnk" \
"$INSTDIR\Uninstall.exe" "" "$INSTDIR\Uninstall.exe" 0
CreateShortCut     "$SMPROGRAMS\RasWin\RasWin.lnk" \
"$INSTDIR\RasWin.exe" "" "$INSTDIR\RasWin.exe" 0


; >>> environment variable

Push "RASMOLPATH"
Push "$INSTDIR"
Call WriteEnvStr

SectionEnd

Section    "Install G. A. Pozhvanov's INI for initial file display" SecInstINI

SectionIn 1 2

SetShellVarContext  all
SetOutPath "$INSTDIR"
File       "rasmol.ini"

SectionEnd


Section "Place RasWin Shortcut on Desktop" SecShortcut

SectionIn 1 2 3

SetShellVarContext  all

CreateShortCut "$DESKTOP\RasWin.lnk" "$INSTDIR\RasWin.exe" 

SectionEnd

SectionGroup "File Extensions" SecFileExt

Section "Register .pdb file extension" SecRegPDB

SectionIn 1 2 3

WriteRegStr HKCR ".pdb" "" "RasWin.Document"
SectionEnd

Section "Register .ent file extension" SecRegENT

SectionIn 1 2 3

WriteRegStr HKCR ".ent" "" "RasWin.Document"
SectionEnd

Section "Register .cif file extension" SecRegCIF

SectionIn 1 2 3

WriteRegStr HKCR ".cif" "" "RasWin.Document"
SectionEnd

Section "Register .scr file extension" SecRegSCR

SectionIn 1 3

WriteRegStr HKCR ".scr" "" "RasWin.Script"
SectionEnd

Section "Register .spt file extension" SecRegSPT

SectionIn 1 2 3

WriteRegStr HKCR ".spt" "" "RasWin.Script"
SectionEnd

Section "Register .rsm file extension" SecRegRSM

SectionIn 1 2 3

WriteRegStr HKCR ".rsm" "" "RasWin.Script"
SectionEnd

Section "Register .rsml file extension" SecRegRSML

SectionIn 1 2 3

WriteRegStr HKCR ".rsml" "" "RasWin.Script"
SectionEnd

Section  "Register .ras file extension" SecRegRAS

SectionIn 1 3

WriteRegStr HKCR ".ras" "" "RasWin.Script"
SectionEnd


Section "Define RasWin Document Type" SecDocType

SectionIn 1 2 3

WriteRegStr HKCR "RasWin.Document" "" "RasMol RasWin Document"
WriteRegStr HKCR "RasWin.Document\DefaultIcon" "" "$INSTDIR\raswin.exe,1"
ReadRegStr $R0 HKCR "RasWin.Document\shell\open\command" ""
StrCmp $R0 "" 0 no_rdocopen
  WriteRegStr HKCR "RasWin.Document\shell" "" "open"
  WriteRegStr HKCR "RasWin.Document\shell\open\command" "" '$INSTDIR\RasWin.exe "%1"'
no_rdocopen:
WriteRegStr HKCR "RasWin.Script" "" "RasMol RasWin Script"
WriteRegStr HKCR "RasWin.Script\DefaultIcon" "" "$INSTDIR\raswin.exe,2"
StrCmp $R0 "" 0 no_rscropen
  WriteRegStr HKCR "RasWin.Script\shell" "" "open"
  WriteRegStr HKCR "RasWin.Script\shell\open\command" "" '$INSTDIR\RasWin.exe -script "%1"'
no_rscropen:
SectionEnd

SectionGroupEnd

Section "Install Sample Data" SecSampData

SectionIn 1 2 3

CreateDirectory "$INSTDIR\Data"
SetOutPath "$INSTDIR\Data"
File       "..\..\data\1crn.pdb"
File       "..\..\data\3cro.pdb"
File       "..\..\data\4ins.CIF"
SectionEnd



; >>> Descriptions

!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
  !insertmacro MUI_DESCRIPTION_TEXT ${SecInstRasWin} "Basic install of RasMol RasWin executable in $INSTDIR and start menu"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecInstINI} "Install of Gregory A. Pozhvanov's rasmol.ini for initial display of files in $INSTDIR"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecShortCut} "Put a RasWin Shortcut on the Desktop"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecFileExt} "Define the .pdb, .ent, .cif, .scr, .spt, .rsm, .rsml and .ras file extensions and document types"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecRegPDB} "Define .pdb file extension as RasWin.Document"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecRegENT} "Define .ent file extension as RasWin.Document"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecRegCIF} "Define .cif file extension as RasWin.Document"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecRegSCR} "Define .scr file extension as RasWin.Script"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecRegSPT} "Define .spt file extension as RasWin.Script"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecRegRSM} "Define .rsm file extension as RasWin.Script"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecRegRSML} "Define .rsml file extension as RasWin.Script"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecRegRAS} "Define .ras file extension as RasWin.Script"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecDoctype} "Define RasMol RasWin Document (RasWin.Document) and Script (RasWin.Script) types"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecSampData} "Install sample data files in $INSTDIR\Data"
!insertmacro MUI_FUNCTION_DESCRIPTION_END


; >>> Installer Functions

Function .onInit
!insertmacro MUI_LANGDLL_DISPLAY
FunctionEnd

Function .onInstSuccess
MessageBox MB_OK "You have successfully installed RasWin."
FunctionEnd
 
 


 
; >>> Uninstaller Section

Section     "Uninstall"
SetShellVarContext  all
Delete      "$INSTDIR\RasMolReferenceCard.pdf"
Delete      "$INSTDIR\rasmol.ini"
Delete      "$INSTDIR\raswin.exe"
Delete      "$INSTDIR\GPL.txt"
Delete      "$INSTDIR\NOTICE.txt"
Delete      "$INSTDIR\RASLIC.txt"
Delete      "$INSTDIR\rasmol.hlp"
Delete      "$INSTDIR\raswin.hlp"
Delete      "$INSTDIR\raswin.ico"
Delete      "$INSTDIR\raswin_doc.ico"
Delete      "$INSTDIR\raswin_scr.ico"
Delete      "$DESKTOP\RasWin.lnk"
Delete      "$SMPROGRAMS\RasWin\*.*"
RmDir       "$SMPROGRAMS\RasWin"
Delete      "$INSTDIR\Data\1crn.pdb"
Delete      "$INSTDIR\Data\3cro.pdb"
Delete      "$INSTDIR\Data\4ins.CIF"
RmDir       "$INSTDIR\Data"

Delete      "$INSTDIR\Uninstall.exe"
RMDir       "$INSTDIR"
DeleteRegKey /ifempty SHCTX "Software\RasWin"
DeleteRegKey SHCTX "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\RasWin"
DeleteRegKey HKCR "RasWin.Document\shell\open\command"
DeleteRegKey HKCR "RasWin.Document\shell"
DeleteRegKey HKCR "RasWin.Document\DefaultIcon"
DeleteRegKey HKCR "RasWin.Document"
DeleteRegKey HKCR "RasWin.Script\shell\open\command"
DeleteRegKey HKCR "RasWin.Script\shell"
DeleteRegKey HKCR "RasWin.Script\DefaultIcon"
DeleteRegKey HKCR "RasWin.Script"

ReadRegStr $R0 HKCR ".pdb" ""
StrCmp $R0  "RasWin.Document" 0 +2
  DeleteRegKey HKCR ".pdb"

ReadRegStr $R0 HKCR ".ent" ""
StrCmp $R0  "RasWin.Document" 0 +2
  DeleteRegKey HKCR ".ent"

ReadRegStr $R0 HKCR ".cif" ""
StrCmp $R0  "RasWin.Document" 0 +2
  DeleteRegKey HKCR ".cif"

ReadRegStr $R0 HKCR ".scr" ""
StrCmp $R0  "RasWin.Script" 0 +2
  DeleteRegKey HKCR ".scr"

ReadRegStr $R0 HKCR ".spt" ""
StrCmp $R0  "RasWin.Script" 0 +2
  DeleteRegKey HKCR ".spt"

ReadRegStr $R0 HKCR ".rsm" ""
StrCmp $R0  "RasWin.Script" 0 +2
  DeleteRegKey HKCR ".rsm"

ReadRegStr $R0 HKCR ".rsml" ""
StrCmp $R0  "RasWin.Script" 0 +2
  DeleteRegKey HKCR ".rsml"

ReadRegStr $R0 HKCR ".ras" ""
StrCmp $R0  "RasWin.Script" 0 +2
  DeleteRegKey HKCR ".ras"


Push         "RASMOLPATH"
Call         un.DeleteEnvStr

SectionEnd



; >>> Uninstaller Functions

Function un.onInit
!insertmacro MUI_UNGETLANGUAGE
FunctionEnd

Function un.onUninstSuccess
MessageBox MB_OK "You have successfully uninstalled RasWin."
FunctionEnd

; >>> Environment Variables Functions

!define ALL_USERS
#
#  The following functions are from
#
#  http://nsis.sourceforge.net/Setting_Environment_Variables
#
!include WinMessages.nsh
 
!ifndef WriteEnvStr_RegKey
  !ifdef ALL_USERS
    !define WriteEnvStr_RegKey \
       'HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment"'
  !else
    !define WriteEnvStr_RegKey 'HKCU "Environment"'
  !endif
!endif
# WriteEnvStr - Writes an environment variable
# Note: Win9x systems requires reboot
#
# Example:
#  Push "HOMEDIR"           # name
#  Push "C:\New Home Dir\"  # value
#  Call WriteEnvStr
#
Function WriteEnvStr
  Exch $1 ; $1 has environment variable value
  Exch
  Exch $0 ; $0 has environment variable name
  Push $2
 
  Call IsNT
  Pop $2
  StrCmp $2 1 WriteEnvStr_NT
    ; Not on NT
    StrCpy $2 $WINDIR 2 ; Copy drive of windows (c:)
    FileOpen $2 "$2\autoexec.bat" a
    FileSeek $2 0 END
    FileWrite $2 "$\r$\nSET $0=$1$\r$\n"
    FileClose $2
    SetRebootFlag true
    Goto WriteEnvStr_done
 
  WriteEnvStr_NT:
      WriteRegExpandStr ${WriteEnvStr_RegKey} $0 $1
      SendMessage ${HWND_BROADCAST} ${WM_WININICHANGE} \
        0 "STR:Environment" /TIMEOUT=5000
 
  WriteEnvStr_done:
    Pop $2
    Pop $0
    Pop $1
FunctionEnd
 
#
# un.DeleteEnvStr - Removes an environment variable
# Note: Win9x systems requires reboot
#
# Example:
#  Push "HOMEDIR"           # name
#  Call un.DeleteEnvStr
#
Function un.DeleteEnvStr
  Exch $0 ; $0 now has the name of the variable
  Push $1
  Push $2
  Push $3
  Push $4
  Push $5
 
  Call un.IsNT
  Pop $1
  StrCmp $1 1 DeleteEnvStr_NT
    ; Not on NT
    StrCpy $1 $WINDIR 2
    FileOpen $1 "$1\autoexec.bat" r
    GetTempFileName $4
    FileOpen $2 $4 w
    StrCpy $0 "SET $0="
    SetRebootFlag true
 
    DeleteEnvStr_dosLoop:
      FileRead $1 $3
      StrLen $5 $0
      StrCpy $5 $3 $5
      StrCmp $5 $0 DeleteEnvStr_dosLoop
      StrCmp $5 "" DeleteEnvStr_dosLoopEnd
      FileWrite $2 $3
      Goto DeleteEnvStr_dosLoop
 
    DeleteEnvStr_dosLoopEnd:
      FileClose $2
      FileClose $1
      StrCpy $1 $WINDIR 2
      Delete "$1\autoexec.bat"
      CopyFiles /SILENT $4 "$1\autoexec.bat"
      Delete $4
      Goto DeleteEnvStr_done
 
  DeleteEnvStr_NT:
    DeleteRegValue ${WriteEnvStr_RegKey} $0
    SendMessage ${HWND_BROADCAST} ${WM_WININICHANGE} \
      0 "STR:Environment" /TIMEOUT=5000
 
  DeleteEnvStr_done:
    Pop $5
    Pop $4
    Pop $3
    Pop $2
    Pop $1
    Pop $0
FunctionEnd
 
!ifndef IsNT_KiCHiK
!define IsNT_KiCHiK
 
#
# [un.]IsNT - Pushes 1 if running on NT, 0 if not
#
# Example:
#   Call IsNT
#   Pop $0
#   StrCmp $0 1 +3
#     MessageBox MB_OK "Not running on NT!"
#     Goto +2
#     MessageBox MB_OK "Running on NT!"
#
!macro IsNT UN
Function ${UN}IsNT
  Push $0
  ReadRegStr $0 HKLM \
    "SOFTWARE\Microsoft\Windows NT\CurrentVersion" CurrentVersion
  StrCmp $0 "" 0 IsNT_yes
  ; we are not NT.
  Pop $0
  Push 0
  Return
 
  IsNT_yes:
    ; NT!!!
    Pop $0
    Push 1
FunctionEnd
!macroend
!insertmacro IsNT ""
!insertmacro IsNT "un."
 
!endif ; IsNT_KiCHiK

 
