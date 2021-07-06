/* Author: Allison Delgado
   Class: CS202 Summer 2021
   The Date class holds the date that an event occurs at.
   It is the base class since all other classes are a date
   plus more.
   
   Last updated: July 5, 2021
 */

class Date {
public:
  Date();
  Date(int month, int day, int year);
  ~Date();
  int change_date(int month, int day, int year);
  int display_date();
  int compare(int month, int day, int year);
  
protected:
  int month;
  int day;
  int year;
};
