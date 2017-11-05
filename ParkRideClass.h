#ifndef PARKRIDECLASS_H_INCLUDED
#define PARKRIDECLASS_H_INCLUDED

#include <iostream>
#include <string>

class ParkRideClass
{

  public:
    ParkRideClass(
        std::string inName,
        int inSeats
    );
    void printName();
    int getNumSeats();
    bool addRider();
    void unloadRiders();

  private: 
    std::string attractionName;
    int numSeats;
    int filledSeats;

};

#endif  // PARKRIDECLASS_H_INCLUDED
