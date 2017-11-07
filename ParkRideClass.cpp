#include <iostream>
#include <stdio.h>
#include <string>

#include "ParkRideClass.h"
#include "LinkedNodeClass.h"
#include "SortedListClass.h"

// constructor
ParkRideClass::ParkRideClass(std::string inName, int inSeats)
{
  attractionName = inName;
  numSeats = inSeats;
}

// prints the name of the attraction
void ParkRideClass::printName()
{
  std::cout << "Name of attraction: " << attractionName << "\n";
}

// get number of seats on this attraction
int ParkRideClass::getNumRiders()
{
  return myRiders.getNumElems();
}

// attempt to add a rider
bool ParkRideClass::addRider(int newRider)
{
  filledSeats = myRiders.getNumElems();
  if (filledSeats < numSeats)
  {
    myRiders.insertValue(newRider);
    return true;
  }
  else
  {
    //printf("Car is full! \n");
    return false;
  }
}

// empty the car of all riders
void ParkRideClass::unloadRiders()
{
  myRiders.clear();
}
