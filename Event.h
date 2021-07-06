/* Author: Allison Delgado
   Class: CS202 Summer 2021
   The Event class has information pertaining to 
   where the event takes place and who is going.
   It inherits Time and therefore Date. This file
   also contains the 3 classes that directly inherit Event:
   Beach, Shopping, and Restaurant.

   Last updated: July 6, 2021
 */

#include "Time.h"
#include "Nodes.h"
#include <vector>
#include <string>

class Event : public Time {
public:
  Event();
  ~Event();
  int set_name(char* name); //set the name of the event
  int set_people(char* people); //set who is going to the event
  int change_name(char* name); //change the name of the event
  int change_people(char* people); //change who is going
  //set location of event:
  int set_location(int street_num, char* street, char* city, char* state);
  //change location of event:
  int change_location(int street_num, char* street, char* city, char* state);
  int display_time(); //display the time of the event
  int display_place(); //display the location of the event

  //date functions:
  int change_date(int date);
  int display_date();
  int compare(int to_compare);

  //time functions
  int change_start_time(int time, bool is_pm);
  int set_duration(int duration);
  int change_duration(int duration);
  int display();
  int compare(int time, bool is_pm);
protected:
  char* name; //name of event
  char* people_going; //who is going

  //pieces of an address:
  int street_num;
  char* street;
  char* city;
  char* state;

  int date; //represented in 6 digits
  int time; //represented in 4 digits (hours and mins)
  bool is_pm;
  int duration; //represented in 4 digits (hours and mins)
};

class Beach : public Event {
public:
  Beach(); //constructor
  Beach(char* items, char* directions, char* food); //set up beach details
  Beach(const Beach & source); //copy constructor
  ~Beach(); //destructor
  int add_items(char* new_items); //add items to a vector of what to bring
  int remove_items(char* to_remove); //remove items from the vector
  int change_directions(char* new_directions); //change directions to the beach
  int change_food_plans(char* new_plans); //change your food plans
  int display(); //display beach plan info
protected:
  std::vector<std::string> items_to_bring; //a vector to store what to bring
  char* directions; //directions to the beach
  std::string food_plans; //what you are going to do for food
};


class Shopping : public Event {
public:
  Shopping(); //constructor
  Shopping(char* stores, char* to_buy, int budget); //set up shopping details
  Shopping(const Shopping & source); //copy constructor
  ~Shopping(); //destructor
  int add_stores(char* to_add); //add stores to the array of LLL
  int remove_stores(char* to_remove); //remove stores from the array of LLL
  int add_items(char* to_add); //add items to the array of LLL
  int remove_items(char* to_remove); //remove items from the LLL
  int change_budget(int new_budget); //change the budget
  int display(); //display shopping details
protected:
  char* stores; //what stores to visit
  char* what_to_buy; //shopping list
  int budget; //how much you want to spend
};

class Restaurant : public Event {
public:
  Restaurant(); //constructor
  Restaurant(char* cuisine, char* name, int budget); //set up restaurant details
  Restaurant(const Restaurant & source); //copy constructor
  ~Restaurant(); //destructor
  int change_cuisine(char* new_cuisine); //change cuisine
  int change_restaurant(char* new_name); //change restaurant
  int change_budget(int new_budget); //change budget
  int display(); //display restaurant details
protected:
  char* cuisine_type; //type of restaurant
  char* name; //name of restaurant
  int budget; //how much you want to spend
};
