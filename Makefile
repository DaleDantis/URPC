URPC: URPC.o
	./URPC.o
	# gdb ./URPC.o

URPC.o: URPC.cpp
	g++ URPC.cpp -Wall -std=c++11 -o URPC.o
	# g++ URPC.cpp -g -Wall -std=c++11 -o URPC.o


clean: 
	rm -f URPC.o