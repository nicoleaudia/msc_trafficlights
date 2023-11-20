#include <iostream>
#include "time.h"

using namespace std;

Time::Time()
  : theHour(0), theMins(0), theSecs(0) {
}


Time::Time(int hours, int mins, int secs)
  : theHour(hours), theMins(mins), theSecs(secs) {
}


void Time::add(Time &anotherTime) {
  int s = theSecs + anotherTime.theSecs;
  int m = theMins + anotherTime.theMins + (s/60); //sums minutes passed in and any minutes calculated if seconds total (int s) exceeds 60 (60 secs in 1 min)

  this->theSecs = s%60; //%60 to find value of seconds that will appear on a clock (displays 0-59 seconds)
  this->theMins = m%60; //%60 to find value of minutes that will appear on a clock (displays 0-59 minutes)
  this->theHour = (theHour + anotherTime.theHour + m/60)%24; //sums hours, including any hours calculated if minutes (int m) total exceeds 60 (60 min in 1 hour). %24 because the clock only displays 0-23 hours, then resets at 0.
}


//friend operator that overloads << operator to output in the format "hours : minutes : seconds"
ostream& operator << (ostream& os, Time& time){
  os << time.theHour << ':' << time.theMins << ':' << time.theSecs; 
  return os;
}



