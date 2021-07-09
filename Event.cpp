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
Time::Time() : date(0), event_time(0), is_pm(false){

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
  event_time = t;
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
  std::cout << "   " << event_time[0] << event_time[1] << ":" << event_time[2] << event_time[3] << std::endl;
}

//returns 1 for a match, 0 for not a match
int Time::compare(std::string input_time, bool input_is_pm) const{
  if(input_time == event_time && input_is_pm == is_pm){
    return 1;
  }
  return 0;
}

//******************* EVENT FUNCTIONS *****************

//constructor with initialization list to initialize all fields
Event::Event() : Time(), street_num(0), street(nullptr), city(nullptr), state(nullptr), name(nullptr), people_going(nullptr){
  
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
  srand(time(NULL));
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

//initialization list to initialize all fields and call the parent constructor
Beach::Beach() : Event(), directions(nullptr), food_plans(nullptr){

}

//destructor to deallocate all dynamic memory
Beach::~Beach(){
  delete [] directions;
  delete [] food_plans;
  directions = nullptr;
  food_plans = nullptr;
}

//copy constructor
Beach::Beach(const Beach & source){
  directions = new char[strlen(source.directions) + 1];
  strcpy(directions, source.directions);
  food_plans = new char[strlen(source.food_plans) + 1];
  strcpy(food_plans, source.food_plans);
}

//set up beach fields
Beach::Beach(std::vector<std::string> items, char* dir, char* f){
  items_to_bring = items;
  strcpy(directions, dir);
  strcpy(food_plans, f);
}

//passed in a char array of new items to add, adds to vector
void Beach::add_items(std::vector<std::string> new_items){
  for(std::vector<std::string>::iterator i = new_items.begin(); i!=new_items.end(); ++i){
    items_to_bring.push_back(*i);
  }
}

//passed in a char array of items to remove, removes from vector
void Beach::remove_items(std::vector<std::string> to_remove){
  for(std::vector<std::string>::iterator j = to_remove.begin(); j!=to_remove.end(); ++j){
    for(std::vector<std::string>::iterator i = items_to_bring.begin(); i!=items_to_bring.end(); ++i){
      if((*i) == (*j)){
	items_to_bring.erase(i);
	break;
      }
    }  
  }
}

//displays info about beach
void Beach::display(){
  std::cout << "Items to bring: " << std::endl;
  for(std::vector<std::string>::iterator i = items_to_bring.begin(); i!=items_to_bring.end(); ++i){
    std::cout << (*i) << std::endl;
  }
  std::cout << "Directions: " << std::endl;
  std::cout << "   " << directions << std::endl;
  std::cout << "Food plans: " << std::endl;
  std::cout << "   " << food_plans << std::endl;
}

//a function to display a pretend weather forecast (if this were a real
//application, this would be accurate and not made up)
void Beach::check_weather(){
  srand (time(NULL));
  int n = rand() % 36 + 75; //random number between 75 and 110 degrees
  std::cout << "It should be " << n << " degrees at the beach." << std::endl;
}

//******************* SHOPPING FUNCTIONS *****************

//initialization list to initialize fields and call the parent constructor
Shopping::Shopping() : Event(), budget(0){
  
}

//set up shopping fields
Shopping::Shopping(std::vector<std::string> s, std::vector<std::string> buy_list, int b){
  stores = s;
  what_to_buy = buy_list;
  budget = b;
}

//push back new items to the list of stores to visit
void Shopping::add_stores(std::vector<std::string> to_add){
  for(std::vector<std::string>::iterator i = to_add.begin(); i!=to_add.end(); ++i){
    stores.push_back(*i);
  }
}

//remove stores from the list
void Shopping::remove_stores(std::vector<std::string> to_remove){
  for(std::vector<std::string>::iterator j = to_remove.begin(); j!=to_remove.end(); ++j){
    for(std::vector<std::string>::iterator i = stores.begin(); i!=stores.end(); ++i){
      if((*i) == (*j)){
	stores.erase(i);
	break;
      }
    }  
  }

}

//add items to buy to the list
void Shopping::add_items(std::vector<std::string> to_add){
  for(std::vector<std::string>::iterator i = to_add.begin(); i!=to_add.end(); ++i){
    what_to_buy.push_back(*i);
  }
}

//remove items to buy from the list
void Shopping::remove_items(std::vector<std::string> to_remove){
  for(std::vector<std::string>::iterator j = to_remove.begin(); j!=to_remove.end(); ++j){
    for(std::vector<std::string>::iterator i = what_to_buy.begin(); i!=what_to_buy.end(); ++i){
      if((*i) == (*j)){
	what_to_buy.erase(i);
	break;
      }
    }  
  }

}

//display shopping info
void Shopping::display(){
  std::cout << "Stores to visit: " << std::endl;
  for(std::vector<std::string>::iterator it = stores.begin(); it!=stores.end(); ++it){
    std::cout << (*it) << std::endl;
  }
  std::cout << "List of items to buy: " << std::endl;
  for(std::vector<std::string>::iterator i = what_to_buy.begin(); i!=what_to_buy.end(); ++i){
    std::cout << (*i) << std::endl;
  }
  std::cout << "Budget" << budget << std::endl;
}

//******************* RESTAURANT FUNCTIONS *****************

//initialization list to initialize all fields and call parent constructor
Restaurant::Restaurant() : Event(), cuisine_type(""), name(""), budget(0), yelp_review(""), reviewed(false){
  
}

//a function to read in all restaurant fields
void Restaurant::read(){
  std::string n;
  std::string c;
  int b = 0;
  
  std::cout << "Enter the name of the restaurant." << std::endl;
  std::getline(std::cin, n);
  std::cin.ignore(1000, '\n');
  name = n;
  std::cout << "Enter the cuisine type of " << n << std::endl;
  std::getline(std::cin, c);
  std::cin.ignore(1000, '\n');
  cuisine_type = c;
  std::cout << "Enter your budget for the restaurant." << std::endl;
  std::cin >> b;
  std::cin.ignore(1000, '\n');
  budget = b;
}

//a function to display all restaurant details
void Restaurant::display(){
  std::cout << "Restaurant: " << name << std::endl;
  std::cout << "Cuisine: " << cuisine_type << std::endl;
  std::cout << "Budget: " << budget << std::endl;
  if (reviewed == true){
    std::cout << "Review: " << stars << " stars." << std::endl;
    std::cout << yelp_review << std::endl;
  }
}

//a function to display the restaurant's "phone number" (randomly generated)
//in a real application, this would be an accurate number and not made up
void Restaurant::contact_info(){
  std::cout << "Restaurant's phone number: ";
  srand(time(NULL));
  for(int i = 0; i < 10; i++){
    std::cout << rand() % 10;
  }
}

//a function to let the user write a yelp review of the restaurant
void Restaurant::write_yelp_review(){
  int num = 0;
  std::string rating;

  std::cout << "How many stars would you rate this restaurant? (0-5)" << std::endl;
  std::cin >> num;
  std::cin.get();
  std::cout << "Please add a description of your rating. " << std::endl;
  std::getline(std::cin, rating);
  std::cin.ignore(1000, '\n');
  yelp_review = rating;
  reviewed = true;
}
