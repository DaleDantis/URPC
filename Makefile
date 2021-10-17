URPC: URPC.o
	./URPC.o

URPC.o: URPC.cpp
	rm -f URPC.o
	g++ URPC.cpp -Wall -std=c++11 -o URPC.o


clean: 
	rm -f URPC.o