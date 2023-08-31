test:
	g++ -c main.cpp
	g++ -g -o out1 main.o
	g++ -O3 -o optimise1 main.o
	./out1

	g++ -c main2.cpp
	g++ -g -o out2 main2.o
	g++ -O3 -o optimise2 main2.o
	./out2