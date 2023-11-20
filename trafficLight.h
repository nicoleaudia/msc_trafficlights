/* trafficLights.h - header file for the class trafficLights */

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "time.h"

/*********************** Class TrafficLight ***************************/


/* Purpose: Defines data type Colour to fix possible values for a traffic light's colour to three options: 
 * red (0), yellow (1), and green (2). */
enum Colour { red, yellow, green };


/* Purpose: Defines class that represents traffic lights. */
class TrafficLight {

public:

  /* Purpose: Constructs a TrafficLight object with light_colour initialized to red and a NULL value for partner. 
   *
   * Should be called if you do not want another TrafficLight object to be assigned as this object's partner.  
   *
   * @param delay_time: Takes a time object that stores the object's delay time 
   * (ie, time before the light changes colour) in the format hours, minutes, seconds.
   *
   * @param name: Takes a char array that stores the name of the TrafficLight object.
   */
  TrafficLight(Time delay_time, char* name);


  /* Purpose: Constructs a TrafficLight object with light_colour initialized to red and a partner assigned
   * (passed in as parameter). 
   *
   * Should be called if you want to assign a specific other TrafficLight object as this object's partner,
   * and want to correspondingly assign this object as that object's partner.
   *
   * @param delay_time: Takes a time object that stores the object's delay time 
   * (ie, time before the light changes colour) in the format hours, minutes, seconds.
   *
   * @param name: Takes a char array that stores the name of the TrafficLight object.
   *
   * @param partner: Takes a TrafficLight object to be assigned as this object's partner.
   */
  TrafficLight(Time delay_time, char* name, TrafficLight& partner); 


  /* Purpose: Assesses light colour of TrafficLight object and object's partner. 
   * Changes light colour(s), adds time to the global clock according to the object's delay time(s), 
   * and prints status message when light changes colour.
   */
  void carWantsToCross();


  /* Purpose: Sets time of global clock to a specific time.
   *
   * @param global_clock: Takes a Time object to be used to store the time in the format hours, minutes, seconds.
   */
  static void setTheTime(Time& global_clock);
  

  friend std::ostream& operator << (std::ostream&, const TrafficLight*);

private:

  /* Purpose: Time object to store the TrafficLight object's delay time 
   * (ie, time before the light changes colour) in the format hours, minutes, seconds. */
  Time delay_time;

  
  /* Purpose: Char array to store the name of a TrafficLight object. */
  char* name;

  
  /* Purpose: Stores a TrafficLight object to be the partner of this TrafficLight object. */
  TrafficLight* partner;

  
  /* Purpose: Stores the colour for a TrafficLight object from the Colour enumeration. */
  Colour light_colour;

  
  /* Purpose: Stores the time in the format hours, minutes, seconds. */
  static Time global_clock;

  
  /* Purpose: Attempts to change the light colour of a TrafficLight object to red.
   *
   * If the object's light colour is yellow, its light colour changes to red, and the request_green
   * function is called for the object's partner (another TrafficLight object). See the request_green
   * function for details.
   *
   * If the object's light colour is not yellow, its light colour changes to yellow. In order to prevent illegal
   * colour pairings between an object and its partner (ex: both objects have a light colour of green), 
   * the request_green function is then called for the object's partner (another TrafficLight object). See the
   * request_green function for details. As a result, when this request_red function exits, the object it was
   * called on will have a light colour of red.
   *
   * This function also adds time to the global clock based on the object's delay time and prints a status
   * message upon light colour change.
   *
   * This function should only be called when the light colour of a TrafficLight object is either green or yellow,
   * and if the goal is for the light colour to be red.
   */
  void request_red();


  /* Purpose: Attempts to change the light colour of a TrafficLight object to green. 
   *
   * If the object's light colour is yellow, its light colour changes to green.
   *
   * If the object's light colour is not yellow, its light colour changes to yellow. In order to prevent illegal
   * colour pairings between an object and its partner (ex: both objects have a light colour of green), 
   * the request_red function is then called for the object's partner (another TrafficLight object). See the
   * request_green function for details. As a result, when this request_green function exits, the object 
   * it was called on will have a light colour of green.
   *
   * This function also adds time to the global clock based on the object's delay time and prints a status
   * message upon light colour change.
   *
   * This function should be called when the light colour of a TrafficLight object is either red or yellow,
   * and if the goal is for the light colour to be green.
   */
  void request_green();

  /* Purpose: Prints a status message including the value stored in global_clock, the name of the TrafficLight 
   * object that changes colour, and the object's new colour. */
  void print_status_message();
};

#endif

