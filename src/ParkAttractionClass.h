#ifndef PARKATTRACTIONCLASS_H_INCLUDED
#define PARKATTRACTIONCLASS_H_INCLUDED

#include <iostream>
#include <string>

class ParkAttractionClass
{

  public:
    ParkAttractionClass(
        std::string inName,
        int inSeats
    );
    void printName();
    int getNumSeats();

  private: 
    std::string attractionName;
    int numSeats;

};

#endif  // PARKATTRACTIONCLASS_H_INCLUDED