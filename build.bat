@echo off

set compiler_options= /GR- /nologo /FC /Zi
set linker_options= user32.lib gdi32.lib

IF NOT EXIST build mkdir build
pushd build
cl %compiler_options% ../src/gravy_main.c /link %linker_options% /out:game.exe
popd