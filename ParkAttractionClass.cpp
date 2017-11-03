#include <iostream>
#include <string>

#include "ParkAttractionClass.h"

// constructor
ParkAttractionClass::ParkAttractionClass(std::string inName, int inSeats)
{
  attractionName = inName;
  numSeats = inSeats;
}

// prints the name of the attraction
void ParkAttractionClass::printName()
{
  std::cout << "Name of attaction: " << attractionName << "\n";
}

// get number of seats on this attraction
int ParkAttractionClass::getNumSeats()
{
  return numSeats;
}