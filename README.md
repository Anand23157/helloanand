we read a file using fstream and then we fetch the corresponding data to calculate coumpound intrest and then after calulating compound inrtest we calculate inflation in reverse order in same value and return that value

in second value we did the same except 
To run above the code we need to run this code
   test:
	g++ -c main.cpp
	g++ -g -o out1 main.o
	g++ -O3 -o optimise1 main.o
	./out1

	g++ -c main2.cpp
	g++ -g -o out2 main2.o
	g++ -O3 -o optimise2 main2.o
	./out2
