main: main.o StrVec.o
	g++ -std=c++11 main.o StrVec.o -o main

main.o: main.cc StrVec.h
	g++ -std=c++11 -c main.cc

StrVec.o: StrVec.cc StrVec.h
	g++ -std=c++11 -c StrVec.cc

clean:
	rm -f main *.o