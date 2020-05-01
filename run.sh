g++ -c -std=c++11 LockedQueue.cpp -pthread 
g++ -c  -std=c++11 produce-consume.cpp -pthread 
g++ -c  -std=c++11 thread.cpp -pthread 



g++ -std=c++11 -g main.cpp -o model  LockedQueue.o produce-consume.o thread.o  -pthread 

./model

rm LockedQueue.o produce-consume.o  thread.o
rm model