/* trafficLights.h - header file for the class trafficLights */

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "time.h"

/*********************** Class TrafficLight ***************************/

//declare enum data type Color
enum Color { red, yellow, green };


class TrafficLight {

public:
	
  TrafficLight(Time delay_time,char* name);
  TrafficLight(Time,char*,TrafficLight&); 

  void carWantsToCross();

  static void setTheTime(Time&);

  friend std::ostream& operator << (std::ostream&, TrafficLight*);

private: //I added things here. TypeName variableName;
  
  Time delay_time;
  char* name;
  TrafficLight* partner;
  Color light_color;
  
  static Time global_clock;

  void request_red();
  void request_green();
};

#endif

