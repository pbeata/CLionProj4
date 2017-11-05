#include <iostream>
#include <stdio.h>
#include <string>

#include "ParkRideClass.h"

// constructor
ParkRideClass::ParkRideClass(std::string inName, int inSeats)
{
  attractionName = inName;
  numSeats = inSeats;
  filledSeats = 0;
}

// prints the name of the attraction
void ParkRideClass::printName()
{
  std::cout << "Name of attraction: " << attractionName << "\n";
}

// get number of seats on this attraction
int ParkRideClass::getNumSeats()
{
  return numSeats;
}

// attempt to add a rider
bool ParkRideClass::addRider()
{
  if (filledSeats < numSeats)
  {
    filledSeats += 1;
    return true;
  }
  else
  {
    printf("Ride is full with %d people!\n", filledSeats);
    return false;
  }
}

// empty the car of all riders
void ParkRideClass::unloadRiders()
{
  filledSeats = 0;
}