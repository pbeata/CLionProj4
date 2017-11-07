parkSimulation: random.o ParkRideClass.o main.o 
	g++ -g -Wall random.o ParkRideClass.o main.o -o parkSimulation

main.o: main.cpp
	g++ -c main.cpp -o main.o

ParkRideClass.o: ParkRideClass.cpp ParkRideClass.h
	g++ -c ParkRideClass.cpp -o ParkRideClass.o

random.o: random.cpp random.h
	g++ -c random.cpp -o random.o

clean:
	rm -rf parkSimulation *.o *~ a.out
