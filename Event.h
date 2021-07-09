/* Author: Allison Delgado
   Class: CS202 Summer 2021
   The Event class has information pertaining to 
   where the event takes place and who is going.
   It inherits Time, which manages when an event
   will occur. This file also contains the 3 classes
   that directly inherit Event:
   Beach, Shopping, and Restaurant.

   Last updated: July 6, 2021
 */

#include "Nodes.h"
#include <vector>
#include <string>

class Time {
  Time();
  ~Time();
  void read();
  void display();
  void compare(int time, bool is_pm);
protected:
  int date; //represented in 6 digits
  int time; //represented in 4 digits (hours and mins)
  bool is_pm;
};

class Event : public Time {
public:
  Event();
  ~Event();
  Event(const Event & source); //copy constructor
  
  //read location of event:
  void read();
  void fun_fact(); //a function to print out a made up fun fact about the address
  void display();
protected:
  //pieces of an address:
  int street_num;
  char* street;
  char* city;
  char* state;
  char* name; //name of event
  char* people_going; //who is going
};

class Beach : public Event {
public:
  Beach(); //constructor
  Beach(const Beach & source); //copy constructor
  ~Beach(); //destructor
  Beach(std::vector<std::string> items, char* directions, std::string food);
  void add_items(char* new_items); //add items to a vector of what to bring
  void remove_items(char* to_remove); //remove items from the vector
  void display(); //display beach plan info
  void check_weather(); //displays a pretend weather forecast
protected:
  std::vector<std::string> * items_to_bring; //a vector to store what to bring
  char* directions; //directions to the beach
  char* food_plans; //what you are going to do for food
};


class Shopping : public Event {
public:
  Shopping(); //constructor
  ~Shopping(); //destructor
  Shopping(std::string stores, std::string buy_list, int budget);
  void add_stores(std::string to_add); //add stores to the array of LLL
  void remove_stores(std::string to_remove); //remove stores from the array of LLL
  void add_items(std::string to_add); //add items to the array of LLL
  void remove_items(std::string to_remove); //remove items from the LLL
  void display(); //display shopping details
protected:
  std::string stores; //what stores to visit
  std::string what_to_buy; //shopping list
  int budget; //how much you want to spend
};

class Restaurant : public Event {
public:
  Restaurant(); //constructor
  ~Restaurant(); //destructor
  void read();
  void display(); //display restaurant details
  void contact_info(); //displays restaurant's phone number (made up)
  void write_yelp_review(); //allows user to write a yelp review
protected:
  std::string cuisine_type; //type of restaurant
  std::string name; //name of restaurant
  int budget; //how much you want to spend
  std::string yelp_review;
};
