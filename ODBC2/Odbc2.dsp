# Microsoft Developer Studio Project File - Name="Odbc2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Odbc2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Odbc2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Odbc2.mak" CFG="Odbc2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Odbc2 - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Odbc2 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Odbc2 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ODBC_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "mysql\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ODBC_EXPORTS" /D "NO_TCL" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x413 /d "NDEBUG"
# ADD RSC /l 0x413 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib madCHook.lib mysql/lib/mysqlclient.lib /nologo /dll /machine:I386 /nodefaultlib:"LIBCMT" /out:"Release/nwnx_odbc.dll" /libpath:"libtomcrypt"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "Odbc2 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ODBC_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /ZI /Od /I "mysql\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ODBC_EXPORTS" /D "NO_TCL" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x413 /d "_DEBUG"
# ADD RSC /l 0x413 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib madCHook.lib mysql/lib/mysqlclient.lib /nologo /dll /debug /machine:I386 /nodefaultlib:"LIBCMT" /out:"Debug/nwnx_odbc.dll" /pdbtype:sept /libpath:"libtomcrypt"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "Odbc2 - Win32 Release"
# Name "Odbc2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "sqlite"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\sqlite\alter.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\analyze.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\attach.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\auth.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\btree.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\build.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\callback.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\complete.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\date.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\delete.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\expr.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\fts1.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\fts1.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\fts1_hash.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\fts1_hash.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\fts1_porter.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\fts1_tokenizer.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\fts1_tokenizer1.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\func.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\hash.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\insert.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\keywordhash.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\legacy.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\loadext.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\main.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\opcodes.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\os.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\os_mac.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\os_os2.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\os_unix.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\os_win.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\pager.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\parse.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\pragma.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\prepare.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\printf.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\random.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\select.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\shell.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\sqlite3ext.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\table.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\tclsqlite.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\tokenize.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\trigger.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\update.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\utf.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\util.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\vacuum.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\vdbe.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\vdbeapi.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\vdbeaux.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\vdbefifo.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\vdbemem.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\vtab.c
# End Source File
# Begin Source File

SOURCE=.\sqlite\where.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\crypt_argchk.c
# End Source File
# Begin Source File

SOURCE=..\NWNXdll\IniFile.cpp
# End Source File
# Begin Source File

SOURCE=.\md5.c
# End Source File
# Begin Source File

SOURCE=.\mysql.cpp
# End Source File
# Begin Source File

SOURCE=..\NWNXDLL\NWNXBase.cpp
# End Source File
# Begin Source File

SOURCE=.\NWNXOdbc.cpp
# End Source File
# Begin Source File

SOURCE=.\Odbc.cpp
# End Source File
# Begin Source File

SOURCE=.\ODBC1.cpp
# End Source File
# Begin Source File

SOURCE=.\scorcohook.cpp
# End Source File
# Begin Source File

SOURCE=.\sqlite.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "sqlite 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\sqlite\btree.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\config.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\hash.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\opcodes.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\os.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\os_common.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\os_mac.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\os_unix.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\os_win.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\pager.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\parse.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\sqlite3.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\sqliteInt.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\vdbe.h
# End Source File
# Begin Source File

SOURCE=.\sqlite\vdbeInt.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\db.h
# End Source File
# Begin Source File

SOURCE=..\NWNXDLL\IniFile.h
# End Source File
# Begin Source File

SOURCE=.\mysql.h
# End Source File
# Begin Source File

SOURCE=..\NWNXDLL\NWNXBase.h
# End Source File
# Begin Source File

SOURCE=.\NWNXOdbc.h
# End Source File
# Begin Source File

SOURCE=.\Odbc.h
# End Source File
# Begin Source File

SOURCE=.\ODBC1.h
# End Source File
# Begin Source File

SOURCE=.\scorcohook.h
# End Source File
# Begin Source File

SOURCE=.\sqlite.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\tomcrypt.h
# End Source File
# Begin Source File

SOURCE=.\tomcrypt_argchk.h
# End Source File
# Begin Source File

SOURCE=.\tomcrypt_cfg.h
# End Source File
# Begin Source File

SOURCE=.\tomcrypt_custom.h
# End Source File
# Begin Source File

SOURCE=.\tomcrypt_hash.h
# End Source File
# Begin Source File

SOURCE=.\tomcrypt_macros.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Odbc2.rc
# End Source File
# End Group
# End Target
# End Project
