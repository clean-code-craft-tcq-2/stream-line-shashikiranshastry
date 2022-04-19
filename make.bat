@echo off

g++ -o bin\receiver.exe receiver\receiver.cpp receiver\receiver_main.cpp -Wall -Wextra

IF %ERRORLEVEL% == 0 (
type Input_example.csv | bin\receiver.exe
) ELSE (
echo ****** COMPILATION RECEIVER FAILED! ******
)
