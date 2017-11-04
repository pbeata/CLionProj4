parkSimulation: random.o ParkAttractionClass.o EventClass.o main.o
	g++ -g -Wall random.o ParkAttractionClass.o EventClass.o  main.o -o parkSimulation

main.o: main.cpp
	g++ -c main.cpp -o main.o

EventClass.o: EventClass.cpp EventClass.h
	g++ -c EventClass.cpp -o EventClass.o

ParkAttractionClass.o: ParkAttractionClass.cpp ParkAttractionClass.h
	g++ -c ParkAttractionClass.cpp -o ParkAttractionClass.o

random.o: random.cpp random.h
	g++ -c random.cpp -o random.o

clean:
	rm -rf parkSimulation *.o *~
