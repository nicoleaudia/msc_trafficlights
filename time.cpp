#include <iostream>
#include "time.h"

using namespace std;

//maybe change these to initializer lists, but won't lose marks
Time::Time() {
  this->theHour = 0; //equivalent to theHour = 0
  this->theMins = 0;
  this->theSecs = 0;
  
}

Time::Time(/*Time *this,*/ int hours, int mins, int secs) {
  this->theHour = hours;
  this->theMins = mins;
  this->theSecs = secs;
}

void Time::add(/*Time *this,*/ Time &anotherTime) {
  int s = theSecs + anotherTime.theSecs;
  int m = theMins + anotherTime.theMins + (s/60);
  this->theSecs = s%60;
  this->theMins = m%60;
  this->theHour = (theHour + anotherTime.theHour + m/60)%24;
  
}

ostream& operator << (ostream& os, Time& time){
  os << time.theHour << ':' << time.theMins << ':' << time.theSecs; //single quotes bc char
  return os;
}



