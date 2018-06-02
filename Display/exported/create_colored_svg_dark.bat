@echo off

SET WORKDIR=%~dp0
SET MSXSL=%WORKDIR%\xsl\msxsl.exe
SET XSLFILE=%WORKDIR%\xsl\variable_colors_dark.xsl
SET ORIGINALXSLFILE=%WORKDIR%\xsl\original.xsl
SET INPUTFILE=%WORKDIR%\display_matarial_design.svg
SET OUTPUTPATH=%WORKDIR%\exported
SET PHOTOPATH=%WORKDIR%\..\..\photos
SET INKMATE=C:\Ruby23-x64\bin\inkmake.bat
SET IMAGEMAGICK=magick.exe
SET STARTTIME=%TIME%

cd %WORKDIR%


REM copy content 1:1 from original, but format the code like the rest
ECHO original ...
%MSXSL% %INPUTFILE% %ORIGINALXSLFILE% -o %OUTPUTPATH%\original.svg



REM FOR %%i IN (red pink purple deeppurple indigo blue lightblue cyan teal green lightgreen lime yellow amber orange deeporange brown grey bluegrey black white) do (
	REM FOR %%j IN (red pink purple deeppurple indigo blue lightblue cyan teal green lightgreen lime yellow amber orange deeporange brown grey bluegrey black white) do (
		REM call:SetColor  %%i, %%j
	REM )
REM )

call:SetColor  indigo, red
call:SetColor  indigo, b
call:SetColor  dark, white
call:SetColor  indigo, white
call:SetColor  light, black
call:SetColor  yellow, black



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

IF "%COLOR2%"=="red"         SET SECONDARYHEX=#F44336  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="pink"        SET SECONDARYHEX=#E91E63  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="purple"      SET SECONDARYHEX=#9C27B0  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="deeppurple"  SET SECONDARYHEX=#673AB7  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="indigo"      SET SECONDARYHEX=#3F51B5  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="blue"        SET SECONDARYHEX=#2196F3  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="lightblue"   SET SECONDARYHEX=#03A9F4  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="cyan"        SET SECONDARYHEX=#00BCD4  &  SET SECONDARYBRIGHT=light
IF "%COLOR2%"=="teal"        SET SECONDARYHEX=#009688  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="green"       SET SECONDARYHEX=#4CAF50  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="lightgreen"  SET SECONDARYHEX=#8BC34A  &  SET SECONDARYBRIGHT=dark
IF "%COLOR2%"=="lime"        SET SECONDARYHEX=#CDDC39  &  SET SECONDARYBRIGHT=light
IF "%COLOR2%"=="yellow"      SET SECONDARYHEX=#FFEB3B  &  SET SECONDARYBRIGHT=light
IF "%COLOR2%"=="amber"       SET SECONDARYHEX=#FFC107  &  SET SECONDARYBRIGHT=light
IF "%COLOR2%"=="orange"      SET SECONDARYHEX=#FF9800  &  SET SECONDARYBRIGHT=light
IF "%COLOR2%"=="deeporange"  SET SECONDARYHEX=#FF5722  &  SET SECONDARYBRIGHT=dark
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
REM call %INKMATE% -s %OUTPUTPATH%\%FOLDER% -o %OUTPUTPATH%\%FOLDER%

ECHO.
ECHO Generate GIF..
%IMAGEMAGICK% convert -loop 0 -delay 100^
 %OUTPUTPATH%\%FOLDER%\gui_01_specials.png^
 %OUTPUTPATH%\%FOLDER%\gui_03_signals.png^
 %OUTPUTPATH%\%FOLDER%\gui_05_flags.png^
 %OUTPUTPATH%\%FOLDER%\gui_07_clubs.png^
 %OUTPUTPATH%\%FOLDER%\gui_09_colors.png^
 %OUTPUTPATH%\%FOLDER%\gui_11_arcade.png^
 %OUTPUTPATH%\%FOLDER%\gui_13_tab07.png^
 %OUTPUTPATH%\%FOLDER%\gui_15_settings.png^
 %PHOTOPATH%\gui.gif
GOTO:EOF
