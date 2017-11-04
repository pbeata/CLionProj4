#ifndef EVENTCLASS_H_INCLUDED
#define EVENTCLASS_H_INCLUDED

#include <iostream>

class EventClass
{

  public:
    EventClass(
        char inType,
        int inTime
    );
    char getType();
    int getTime();

  private:
    char type;
    int time;

};

#endif  // EVENTCLASS_H_INCLUDED