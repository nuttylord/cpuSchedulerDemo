DEMO1=1
DEMO2=2
DEMO3=3

demo: demo1 demo2 demo3

demo1: main.o
	g++ -o demo1 main.o -std=c++11
	./ca1_jobs.pl 10 30 15 > demo_input1.txt
	./demo1 $DEMO1

demo2: main.o
	g++ -o demo2 main.o -std=c++11
	./ca1_jobs.pl 15 40 12 > demo_input2.txt
	./demo2 $DEMO2

demo3: main.o
	g++ -o demo3 main.o -std=c++11
	./ca1_jobs.pl 20 60 30 > demo_input3.txt
	./demo3 $DEMO3

main.o: main.cpp
	g++ -c main.cpp -std=c++11

clean:
	rm -rf main.o
	rm -f demo1 demo2 demo3
	rm -f demo_output1 demo_output2 demo_output3
	rm -f demo_input1.txt demo_input2.txt demo_input3.txt
