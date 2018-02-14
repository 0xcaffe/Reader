@echo off

REM set yours enviroment
set CXX=g++
set CXXFLAGS=-c
set LDFLAGS=

cls
echo ::CLEAN::
del /Q bin\*
rd bin
md bin

echo ::COMPLIE::
@echo on
%CXX% %CXXFLAGS% Reader.cpp -o bin/Reader.obj
%CXX% %CXXFLAGS% ReaderTest.cpp -o bin/ReaderTest.obj
%CXX% %CXXFLAGS% main.cpp -o bin/main.obj
%CXX% %CXXFLAGS% test.cpp -o bin/test.obj
@echo off

cd bin
echo ::LINK::
@echo on
%CXX% %LDFLAGS% Reader.obj main.obj -o ../reader.exe
%CXX% %LDFLAGS% Reader.obj ReaderTest.obj test.obj -o ../readerTest.exe
@echo off

cd ..

echo ::TEST::
readerTest.exe

echo ::RUN::
reader.exe


