#include <iostream>
#include "trafficLight.h"
#include "time.h"

using namespace std;

//overloading the operator for the enum Color so cout outputs strings instead of integers
ostream &operator<<(ostream &out, const Color &light_color) {
  switch(light_color){
  case red:
    out << "red"; break;
  case yellow:
    out << "yellow"; break;
  case green:
    out << "green"; break;
  }
  return out;
}


//definition calling default constructor
Time TrafficLight::global_clock;

//first one is TrafficLight namespace(class-specific namespace), second one is constructor
TrafficLight::TrafficLight(/*TrafficLight *this,*/ Time delay_time, char* name){
  this->delay_time = delay_time;
  this->name = name;
  this->partner = NULL; //need to set NULL so doesn't pick junk value as attribute

  light_color = red; 
}

TrafficLight::TrafficLight(/*TrafficLight *this,*/ Time delay_time, char* name, TrafficLight& partner){
  this->delay_time = delay_time;
  this->name = name;
  this->partner = &partner;

  //sets current object to the partner of its partner
  this->partner->partner = this;
  
  light_color = red;
}

void TrafficLight::carWantsToCross(){

  //print intro message
  cout << endl << "***  at " << global_clock << " a car wants to cross light " << this->name << ", with colour: " << this->light_color << endl;

  if (this->light_color == red){
    
    if (partner->light_color == red){
 
      //add time to global clock and change to yellow
      global_clock.add(delay_time);
      light_color = yellow;
      cout << "     at " << global_clock << " " << this->name << " changes colour to " << this->light_color << endl;

      //add time to global clock and change to green
      global_clock.add(delay_time);
      light_color = green;
      cout << "     at " << global_clock << " " << this->name << " changes colour to " << this->light_color << endl; 
    }
    else { // (partner->light_color == green){ //arrow means dereferencing and asking for attribute
      partner->request_red();
      //(*partner).request_red();
      //this->request_red();
      //      (*this).request_red();
    }
  }
}

//bc setTheTime is a static operation, it can only be used at the beginning of the program before any TrafficLight objects are created
void TrafficLight::setTheTime(Time& global_clock){
  TrafficLight::global_clock = global_clock;
}

//infinite loop currently
ostream& operator << (ostream& os, TrafficLight* trafficLight){
  os << trafficLight->name;
  return os;
}


//This method is private within the TrafficLight class and assumes it will only be called if the partner's light is either green or yellow
void TrafficLight::request_red(){
  if (this->light_color == green){
    global_clock.add(this->delay_time);
    this->light_color = yellow;
    partner->request_green();
  }
  else { //partner is yellow
    global_clock.add(this->delay_time);
    this->light_color = red;
    partner->request_green();
  }
  cout << "     at " << global_clock << " " << this->name << " changes colour to " << this->light_color << endl;
}


void TrafficLight::request_green(){
  if (this->light_color == red){
    global_clock.add(this->delay_time);
    this->light_color = yellow;
    partner->request_red();
  }
  else { //this is yellow
    global_clock.add(this->delay_time);
    this->light_color = green;
  }
  cout << "     at " << global_clock << " " << this->name << " changes colour to " << this->light_color << endl;
}
