#include <iostream>

#include "EventClass.h"

// constructor
EventClass::EventClass(char inType, int inTime)
{
  type = inType;
  time = inTime;
}

char EventClass::getType()
{
  return type;
}

int EventClass::getTime()
{
  return time;
}