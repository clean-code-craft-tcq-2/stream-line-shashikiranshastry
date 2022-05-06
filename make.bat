@echo off

g++ -o bin\receiver.exe receiver\receiver.cpp receiver\receiver_main.cpp -Wall -Wextra

IF %ERRORLEVEL% == 0 (
type Input_example.csv | bin\receiver.exe
) ELSE (
echo ****** COMPILATION RECEIVER FAILED! ******
)

g++ -o bin\receiver_test.exe receiver\receiver.cpp receiver\receiver_test.cpp -Wall -Wextra

IF %ERRORLEVEL% == 0 (
type Input_example.csv | bin\receiver_test.exe
) ELSE (
echo ****** COMPILATION TEST RECEIVER FAILED! ******
)
