parkSimulation: random.o ParkAttractionClass.o  main.o
	g++ -g -Wall random.o ParkAttractionClass.o  main.o -o parkSimulation

main.o: main.cpp
	g++ -c main.cpp -o main.o

ParkAttractionClass.o: ParkAttractionClass.cpp ParkAttractionClass.h
	g++ -c ParkAttractionClass.cpp -o ParkAttractionClass.o

random.o: random.cpp random.h
	g++ -c random.cpp -o random.o

clean:
	rm -rf parkSimulation *.o *~
