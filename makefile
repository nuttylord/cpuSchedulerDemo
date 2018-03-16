all: test.exe

test.exe: main.o
	g++ -o test.exe main.o -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

clean: 
	rm main.o test.exe
