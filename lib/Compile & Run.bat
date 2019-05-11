g++ *.cpp -c
move *.o Debug
cd Debug
g++ *.o -o Test.exe
Test.exe
cd..