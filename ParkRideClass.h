#ifndef PARKRIDECLASS_H_INCLUDED
#define PARKRIDECLASS_H_INCLUDED

#include <iostream>
#include <string>

#include "LinkedNodeClass.h"
#include "SortedListClass.h"

class ParkRideClass
{

  public:
    ParkRideClass(
        std::string inName,
        int inSeats
    );
    void printName();
    int getNumRiders();
    bool addRider(int newRider);
    void unloadRiders();

  private: 
    std::string attractionName;
    int numSeats;
    int filledSeats;
    SortedListClass<int> myRiders;

};

#endif  // PARKRIDECLASS_H_INCLUDED
