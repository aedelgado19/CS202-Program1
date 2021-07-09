/* Author: Allison Delgado
   Class: CS202 Summer 2021
   This file contains the member functions for
   Time, Event, Beach, Shopping, and Restaurant.
   It can be tested through the client program,
   main.cpp. 

   Last updated: July 8, 2021
 */

#include "Event.h"

//******************* TIME FUNCTIONS *****************

//constructor with initialization list to initialize all fields
Time::Time() : date(0), time(0), is_pm(false){

}

//set the information for the time class
void Time::read(){
  std::string d;
  std::string t;
  std::string ampm;

  std::cout << "Enter the date of this event. " << std::endl;
  std::cout << "Please use 6 digits (MMDDYY) to represent the date." << std::endl;
  std::cout << "Example: August 1, 2021 would be 080121." << std::endl;
  std::getline(std::cin, d);
  std::cin.ignore(1000, '\n');
  date = d;
  std::cout << "Enter the time of this event. " << std::endl;
  std::cout << "Please use 4 digits (HHMM) where H = hours and M = mins" << std::endl;
  std::cout << "   Example: 4:30 would be 0430" << std::endl;
  std::getline(std::cin, t);
  std::cin.ignore(1000, '\n');
  time = t;
  std::cout << "Is this event in the am or pm? (am/pm)" << std::endl;
  std::getline(std::cin, ampm);
  std::cin.ignore(1000, '\n');
  if(ampm == "am"){
    is_pm = false;
  } else {
    is_pm = true;
  }
}

//display all information regarding time
void Time::display() const{ 
  std::cout << "Date: " << std::endl;
  std::cout << "   " << date[0] << date[1] << "/" << date[2] << date[3] << "/" << date[4] << date[5] << std::endl;
  std::cout << "Time: " << std::endl;
  std::cout << "   " << time[0] << time[1] << ":" << time[2] << time[3] << std::endl;
}

//returns 1 for a match, 0 for not a match
int Time::compare(std::string input_time, bool input_is_pm) const{
  if(input_time == time && input_is_pm == is_pm){
    return 1;
  }
  return 0;
}

//******************* EVENT FUNCTIONS *****************

//constructor with initialization list to initialize all fields
Event::Event() : street_num(0), street(nullptr), city(nullptr), state(nullptr), name(nullptr), people_going(nullptr){
  
}

//destructor to deallocate all dynamic memory
Event::~Event(){
  delete [] street;
  delete [] city;
  delete [] state;
  delete [] name;
  delete [] people_going;
  street = nullptr;
  city = nullptr;
  state = nullptr;
  name = nullptr;
  people_going = nullptr;
}

//copy constructor
Event::Event(const Event & source) : Time(source){
  street = new char[strlen(source.street) + 1];
  strcpy(street, source.street);
  city = new char[strlen(source.city) + 1];
  strcpy(city, source.city);
  state  = new char[strlen(source.state) + 1];
  strcpy(state, source.state);
  name = new char[strlen(source.name) + 1];
  strcpy(name, source.name);
  people_going = new char[strlen(source.people_going) + 1];
  strcpy(people_going, source.people_going);
}

//read in information about the event
void Event::read(){
  int num;
  char* str;
  char* c;
  char* st;
  char* n;
  char* pg;

  //get info
  std::cout << "Creating an address for this event. Please enter the street number: "<< std::endl;
  std::cin >> num;
  std::cin.get();
  std::cout << "Please enter the street name: " << std::endl;
  std::cin.get(str, 30);
  std::cin.get();
  std::cout << "Please enter the city: " << std::endl;
  std::cin.get(c, 30);
  std::cin.get();
  std::cout << "Please enter the state: " << std::endl;
  std::cin.get(st, 30);
  std::cin.get();
  std::cout << "Address complete.\n" << std::endl;
  std::cout << "What would you like to call this event?" << std::endl;
  std::cin.get(n, 50);
  std::cin.get();
  std::cout << "Finally, who is going to this event?"  << std::endl;
  std::cin.get(pg, 100);
  std::cin.get();

  //set the info
  street_num = num;
  strcpy(street, str);
  strcpy(city, c);
  strcpy(state, st);
  strcpy(name, n);
  strcpy(people_going, pg);
}

//a function to print out a pretend fun fact about the location of the event
//in a real application, these facts would be real
void Event::fun_fact(){
  int n = rand() % 5;
  if(n == 0){
    std::cout << "This address was where the Zodiac Killer was found." << std::endl;
  }
  else if (n == 1) {
    std::cout << "There was a Star Wars scene filmed at the location of this event." << std::endl;
  }
  else if (n == 2) {
    std::cout << "That city is home to the largest turtle in the world." << std::endl;
  }
  else if (n == 3) {
    std::cout << "That city holds an annual rubber duck decorating contest." << std::endl;
  }
  else if (n == 4) {
    std::cout << "Legend has it that Brad Pitt will be at this event." << std::endl;
  }
}

void Event::display() const{
  std::cout << "Event title: " << std::endl;
  std::cout << "   " << name << std::endl;
  std::cout << "People going: " << std::endl;
  std::cout << "   " << people_going << std::endl;
  std::cout << "Address: " << std::endl;
  std::cout << street_num << " " << street << " " << city << " " << state << std::endl;
}

//******************* BEACH FUNCTIONS *****************
Beach::Beach() : items_to_bring(nullptr), directions(nullptr), food_plans(nullptr){

}

//destructor to deallocate all dynamic memory
Beach::~Beach(){
  delete [] directions;
  delete [] food_plans;
  delete [] items_to_bring;
  directions = nullptr;
  food_plans = nullptr;
  items_to_bring = nullptr;
}

//copy constructor
Beach::Beach(const Beach & source){
  directions = new char[strlen(source.directions) + 1];
  strcpy(directions, source.directions);
  food_plans = new char[strlen(source.food_plans) + 1];
  strcpy(food_plans, source.food_plans);
  items_to_bring = new char[strlen(source.items_to_bring) + 1];
  strcpy(items_to_bring, source.items_to_bring);
}

//set up beach fields
Beach::Beach(char* items, char* dir, char* f){
  strcpy(items_to_bring, items);
  strcpy(directions, dir);
  strcpy(food_plans, f);
}

void Beach::add_items(char* new_items){
  
}

void Beach::remove_items(char* to_remove){

}

void Beach::display(){

}

void Beach::check_weather(){

}

//******************* SHOPPING FUNCTIONS *****************
Shopping::Shopping(){

}

Shopping::~Shopping(){

}
Shopping::Shopping(std::string stores, std::string buy_list, int budget){

}

void Shopping::add_stores(std::string to_add){

}

void Shopping::remove_stores(std::string to_remove){

}

void Shopping::add_items(std::string to_add){

}

void Shopping::remove_items(std::string to_remove){

}

void Shopping::display(){

}

//******************* RESTAURANT FUNCTIONS *****************

Restaurant::Restaurant(){

}

Restaurant::~Restaurant(){

}

void Restaurant::read(){

}

void Restaurant::display(){

}

void Restaurant::contact_info(){

}

void Restaurant::write_yelp_review(){

}
