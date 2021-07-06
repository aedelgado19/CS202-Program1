/* Author: Allison Delgado
   Class: CS 202 Spring 2021
   The Time.h class inherits Date
   and pertains to how long an event lasts
   and when it starts/ends

   Last updated: July 6, 2021
 */
#include "Date.h"

class Time : public Date {
public:
  Time();
  Time(int hour, int min, bool is_pm);
  ~Time();
  int change_start_time(int hour, int min, bool is_pm);
  int set_duration(int hours, int mins);
  int change_duration(int hours, int mins);
  int display();
  int compare(int hour, int min, bool is_pm);
 protected:
  int start_hours;
  int start_mins;
  bool is_pm;
  int duration_hours;
  int duration_mins;
};
