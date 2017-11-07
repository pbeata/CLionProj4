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
bool ParkRideClass::carIsFull()
{
  filledSeats = myRiders.getNumElems();
  if (filledSeats < numSeats)
  {
    return false;
  }
  else
  {
    return true;
  }
}

// attempt to add a rider
bool ParkRideClass::addRider(int newRider)
{
  if (carIsFull())
  {
    return false;
  }
  else
  {
    myRiders.insertValue(newRider);
    return true;
  }
}

// empty the car of all riders
void ParkRideClass::unloadRiders()
{
  myRiders.clear();
}
