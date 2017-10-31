parkSimulation: random.o main.o
	g++ -g -Wall random.o main.o -o parkSimulation

main.o: main.cpp
	g++ -c main.cpp -o main.o

random.o: random.cpp random.h
	g++ -c random.cpp -o random.o

clean:
	rm -rf parkSimulation *.o *~
