/* time.h - header file for the class Time */

#ifndef TIME_H
#define TIME_H

#include <iostream>

/*********************** Time Class ***************************/

class Time { 

	public:

                /* Purpose: Default constructor for Time. Constructs a Time object with attributes theHour, theMins,
		 * and theSecs all initialized to 0. */
		Time(); 

  
                /* Purpose: Constructs a Time object with attributes theHour, theMins, and theSecs initialized
		 * to the values stored in the parameters hours, mins, and secs, respectively.
		 *
		 * @param hours: Takes an integer representing a number of hours. Should be a value 0 through 23.
		 *
		 * @param mins: Takes an integer representing a number of minutes. Should be a value 0 through 59.
		 * 
		 * @param secs: Takes an integer representing a number of seconds. Should be a value 0 throuh 59.
		 */
		Time(int hours, int mins, int secs);


                /* Purpose: Adds seconds to seconds, minutes to minutes, and hours to hours, taking into account
		 * that a day has 24 hours, an hour has 60 minutes and a minute has 60 seconds. Once the maximum
		 * total of 23 hours, 59 minutes, and 59 seconds is passed, the total will start again at 0 hours,
		 * 0 minutes, and 0 seconds.
		 *
		 * @param anotherTime: Takes a Time object representing an amount of time in the format hours,
		 * minutes, seconds.
     		 */
		void add(Time& anotherTime);
	    
  
                /* Purpose: Delcares the << operator as a friend of the Time function,
		 * granting it access to the members of Time. */
		friend std::ostream& operator << (std::ostream&, const Time&);

	private:

                /* Purpose: Integer that stores a value representing hours on a 24-hour clock.
		 * Should be a value 0 through 23. */
		int theHour;

  
                /* Purpose: Integer that stores a value representing minutes on a 24-hour clock.
		 * Should be a value 0 through 59. */
		int theMins;


                /* Purpose: Integer that stores a value representing seconds on a 24-hour clock.
		 * Should be a value 0 through 59. */
		int theSecs;	
		
};

#endif

