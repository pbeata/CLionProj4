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
    bool delRider();
    void unloadRiders();

  private: 
    std::string attractionName;
    int numSeats;
    int filledSeats;

};

#endif  // PARKRIDECLASS_H_INCLUDED
