@echo off

SET WORKDIR=%~dp0
SET MSXSL=%WORKDIR%\xsl\msxsl.exe
SET XSLFILE=%WORKDIR%\xsl\variable_colors_dark.xsl
SET ORIGINALXSLFILE=%WORKDIR%\xsl\original.xsl
SET INPUTFILE=%WORKDIR%\display_matarial_design.svg
SET OUTPUTPATH=%WORKDIR%\exported
SET INKMATE=C:\Ruby23-x64\bin\inkmake.bat
SET STARTTIME=%TIME%

cd %WORKDIR%


REM copy content 1:1 from original, but format the code like the rest
ECHO original ...
%MSXSL% %INPUTFILE% %ORIGINALXSLFILE% -o %OUTPUTPATH%\original.svg



FOR %%i IN (red pink purple deeppurple indigo blue lightblue cyan teal green lightgreen lime yellow amber orange deeporange brown grey bluegrey dark light) do (
	FOR %%j IN (red pink purple deeppurple indigo blue lightblue cyan teal green lightgreen lime yellow amber orange deeporange brown grey bluegrey black white) do (
		call:SetColor  %%i, %%j
	)
)




ECHO %STARTTIME%
ECHO %TIME%

PAUSE

EXIT


:SetColor
SET COLOR1=%~1
SET COLOR2=%~2

IF "%COLOR1%"=="red"         SET PRIMARYHEX=#F44336    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="pink"        SET PRIMARYHEX=#E91E63    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="purple"      SET PRIMARYHEX=#9C27B0    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="deeppurple"  SET PRIMARYHEX=#673AB7    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="indigo"      SET PRIMARYHEX=#3F51B5    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="blue"        SET PRIMARYHEX=#2196F3    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="lightblue"   SET PRIMARYHEX=#03A9F4    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="cyan"        SET PRIMARYHEX=#00BCD4    &  SET PRIMARYBRIGHT=light
IF "%COLOR1%"=="teal"        SET PRIMARYHEX=#009688    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="green"       SET PRIMARYHEX=#4CAF50    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="lightgreen"  SET PRIMARYHEX=#8BC34A    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="lime"        SET PRIMARYHEX=#CDDC39    &  SET PRIMARYBRIGHT=light
IF "%COLOR1%"=="yellow"      SET PRIMARYHEX=#FFEB3B    &  SET PRIMARYBRIGHT=light
IF "%COLOR1%"=="amber"       SET PRIMARYHEX=#FFC107    &  SET PRIMARYBRIGHT=light
IF "%COLOR1%"=="orange"      SET PRIMARYHEX=#FF9800    &  SET PRIMARYBRIGHT=light
IF "%COLOR1%"=="deeporange"  SET PRIMARYHEX=#FF5722    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="brown"       SET PRIMARYHEX=#795548    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="grey"        SET PRIMARYHEX=#9E9E9E    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="bluegrey"    SET PRIMARYHEX=#607D8B    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="dark"        SET PRIMARYHEX=#212121    &  SET PRIMARYBRIGHT=dark
IF "%COLOR1%"=="light"       SET PRIMARYHEX=#F5F5F5    &  SET PRIMARYBRIGHT=light

IF "%COLOR2%"=="red"         SET SECONDARYHEX=#FF5252  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="pink"        SET SECONDARYHEX=#FF4081  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="purple"      SET SECONDARYHEX=#E040FB  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="deeppurple"  SET SECONDARYHEX=#7C4DFF  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="indigo"      SET SECONDARYHEX=#536DFE  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="blue"        SET SECONDARYHEX=#448AFF  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="lightblue"   SET SECONDARYHEX=#40C4FF  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="cyan"        SET SECONDARYHEX=#18FFFF  &  SET SECONDARYBRIGHT=light
IF "%COLOR2%"=="teal"        SET SECONDARYHEX=#64FFDA  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="green"       SET SECONDARYHEX=#69F0AE  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="lightgreen"  SET SECONDARYHEX=#B2FF59  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="lime"        SET SECONDARYHEX=#EEFF41  &  SET SECONDARYBRIGHT=light
IF "%COLOR2%"=="yellow"      SET SECONDARYHEX=#FFFF00  &  SET SECONDARYBRIGHT=light
IF "%COLOR2%"=="amber"       SET SECONDARYHEX=#FFD740  &  SET SECONDARYBRIGHT=light
IF "%COLOR2%"=="orange"      SET SECONDARYHEX=#FFAB40  &  SET SECONDARYBRIGHT=light
IF "%COLOR2%"=="deeporange"  SET SECONDARYHEX=#FF6E40  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="brown"       SET SECONDARYHEX=#795548  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="grey"        SET SECONDARYHEX=#9E9E9E  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="bluegrey"    SET SECONDARYHEX=#607D8B  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="black"       SET SECONDARYHEX=#000000  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="white"       SET SECONDARYHEX=#ffffff  &  SET SECONDARYBRIGHT=light

call:ExportPNG dark
call:ExportPNG light

GOTO:EOF





:ExportPNG
SET THEME=%~1

SET FOLDER=%COLOR1%_%COLOR2%_%THEME%
ECHO.
ECHO %FOLDER% ...
MKDIR %OUTPUTPATH%\%FOLDER%
%MSXSL% %INPUTFILE% %XSLFILE% -o %OUTPUTPATH%\%FOLDER%\gui.svg ^
  primary_color=%PRIMARYHEX% secondary_color=%SECONDARYHEX% ^
  primary_bright=%PRIMARYBRIGHT% secondary_bright=%SECONDARYBRIGHT% ^
  theme=%THEME%
  
  
copy /Y %WORKDIR%\inkfile %OUTPUTPATH%\%FOLDER%\inkfile
call %INKMATE% -s %OUTPUTPATH%\%FOLDER% -o %OUTPUTPATH%\%FOLDER%

GOTO:EOF
