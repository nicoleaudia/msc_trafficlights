#include <iostream>
#include "trafficLight.h"
#include "time.h"

using namespace std;

//overloads the output operator to output a string instead of an integer value for light_colour
ostream &operator<<(ostream &out, const Colour &light_colour) {
  switch(light_colour){
  case red:
    out << "red"; break;
  case yellow:
    out << "yellow"; break;
  case green:
    out << "green"; break;
  }
  return out;
}


Time TrafficLight::global_clock;


TrafficLight::TrafficLight(Time delay_time, char* name){
  this->delay_time = delay_time;
  this->name = name;
  this->partner = NULL; 

  light_colour = red; 
}


TrafficLight::TrafficLight(Time delay_time, char* name, TrafficLight& partner){
  this->delay_time = delay_time;
  this->name = name;
  this->partner = &partner;

  //sets this object to be the partner of its partner
  this->partner->partner = this;
  
  light_colour = red;
}


void TrafficLight::carWantsToCross(){

  //prints initial message when car wants to cross
  cout << endl << "***  at " << global_clock << " a car wants to cross light " << this->name << ", with colour: " << this->light_colour << endl;

  if (this->light_colour == red){
    
    if (partner->light_colour == red){
 
      //adds time to global clock and changes light colour to yellow
      global_clock.add(delay_time);
      light_colour = yellow;
      print_status_message();

      //adds time to global clock and changes light colour to green
      global_clock.add(delay_time);
      light_colour = green;
      print_status_message();
    }
    
    else {
      
    partner->request_red();
    }
  }
}


void TrafficLight::setTheTime(Time& global_clock){
  TrafficLight::global_clock = global_clock;
}


ostream& operator << (ostream& os, const TrafficLight* trafficLight){
  os << trafficLight->name;
  return os;
}


/* request_red method is private within the TrafficLight class and assumes it will only be called
  if the light is either green or yellow */
void TrafficLight::request_red(){
  if (this->light_colour == green){

    //adds time to global clock, changes light colour to yellow, and calls request_green function for partner
    global_clock.add(this->delay_time);
    this->light_colour = yellow;
    print_status_message();
    partner->request_green();
  }
  
  else {
    
    //adds time to global clock, changes light colour to green, and calls request_green function for partner
    global_clock.add(this->delay_time);
    this->light_colour = red;
    print_status_message();
    partner->request_green();
  }
}


/* request_green method is private within the TrafficLight class and assumes it will only be called 
   if the light is either red or yellow */
void TrafficLight::request_green(){
  if (this->light_colour == red){

    //adds time to global clock, changes light colour to yellow, and calls request_red function for partner
    global_clock.add(this->delay_time);
    this->light_colour = yellow;
    print_status_message();
    partner->request_red();
  }
  
  else {
    
    //adds time to global clock and changes light colour to green
    global_clock.add(this->delay_time);
    this->light_colour = green;
    print_status_message();
  }
}


void TrafficLight::print_status_message(){
  cout << "     at " << global_clock << " " << this->name << " changes colour to " << this->light_colour << endl;
}
