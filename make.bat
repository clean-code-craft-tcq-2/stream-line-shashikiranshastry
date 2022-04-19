@echo off

g++ -o bin\receiver.exe receiver\receiver.cpp -Wall -Wextra

IF %ERRORLEVEL% == 0 (
type Input_example.csv | bin\receiver.exe
) ELSE (
echo ****** COMPILATION RECEIVER FAILED! ******
)
