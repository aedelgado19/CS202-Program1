Nodes.h                                                                                             000644  000765  000024  00000003256 14072136721 012414  0                                                                                                    ustar 00ally                            staff                           000000  000000                                                                                                                                                                         /* Author: Allison Delgado
   Class: CS 202 Spring 2021
   This file contains 4 classes:
   Array, A_Node, C_Node, and Circular_LL.
   A_node and Array work together to make an array of LLL's
   and C_Node and Circular_LL make a circular LL.

   Last updated: July 6, 2021
 */
#include "Event.h"

class A_Node : public Shopping {
public:
  A_Node(); //constructor
  A_Node(const Shopping & source); //copy constructor
  ~A_Node(); //destructor
  A_Node *& go_next(); //move through array of LL 
  int set_next(A_Node* next); //set the next node
  int display_data(char* name); //display data for a particular node
protected:
  A_Node* next;
};

class Array {
public:
  Array(); //constructor
  Array(int size); //set size of array
  Array(const Array & source); //copy constructor
  ~Array(); //destructor
  int insert(A_Node & to_add); //add a node
  int remove(char* name); //remove a node
  int display(); //display the whole DS
  int remove_all(); //remove all nodes
private:
  A_Node ** head;
  int size;
};

class C_Node : public Restaurant {
public:
  C_Node(); //constructor
  C_Node(const Restaurant & source); //copy constructor
  ~C_Node(); //destructor
  C_Node *& go_next(); //move through CLL
  int set_next(C_Node* next); //set the next node
  int display_data(char* name); //display data for a particular node
protected:
  C_Node* next;
};

class Circular_LL {
public:
  Circular_LL(); //constructor
  Circular_LL(const Circular_LL & source); //copy constructor
  ~Circular_LL(); //destructor
  int insert(C_Node *& to_add); //insert a node
  int remove(char* to_remove); //remove a node
  int display(); //display all nodes
  int remove_all(); //remove all nodes;
private:
  C_Node * rear;
};
                                                                                                                                                                                                                                                                                                                                                  Event.cpp                                                                                           000644  000765  000024  00000025607 14072174664 012774  0                                                                                                    ustar 00ally                            staff                           000000  000000                                                                                                                                                                         /* Author: Allison Delgado
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
Time::Time() : date(""), event_time(""), is_pm(false){

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
  date = d;
  std::cout << "Enter the time of this event. " << std::endl;
  std::cout << "Please use 4 digits (HHMM) where H = hours and M = mins" << std::endl;
  std::cout << "   Example: 4:30 would be 0430" << std::endl;
  std::getline(std::cin, t);
  event_time = t;
  std::cout << "Is this event in the am or pm? (am/pm)" << std::endl;
  std::getline(std::cin, ampm);
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
  std::cout << "Budget: " << budget << std::endl;
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
  name = n;
  std::cout << "Enter the cuisine type of " << n << std::endl;
  std::getline(std::cin, c);
  cuisine_type = c;
  std::cout << "Enter your budget for the restaurant." << std::endl;
  std::cin >> b;
  std::cin.get();
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
  for(int i = 0; i < 3; i++){
    std::cout << rand() % 10;
  }
  std::cout << "-";
  for(int i = 0; i < 3; i++){
    std::cout << rand() % 10;
  }
  std::cout << "-";
  for(int i = 0; i < 4; i++){
    std::cout << rand() % 10;
  }
  std::cout << " " << std::endl;
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
  yelp_review = rating;
  reviewed = true;
}
                                                                                                                         Nodes.cpp                                                                                           000644  000765  000024  00000000007 14071157233 012736  0                                                                                                    ustar 00ally                            staff                           000000  000000                                                                                                                                                                         /*
 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         main.cpp                                                                                            000644  000765  000024  00000016403 14072174727 012631  0                                                                                                    ustar 00ally                            staff                           000000  000000                                                                                                                                                                         /* Author: Allison Delgado
   Class: CS202 Summer 2021
   The main class acts as a testing site for
   all public member functions in the classes.
   The aim of this program is to act as a scheduling
   tool for various tasks.

   Last updated: July 5, 2021
 */

#include <iostream>
#include "Event.h"
#include <cstring>
#include <vector>
using namespace std;

void beach(Beach & b);
void shopping(Shopping & s);
void restaurant(Restaurant & r);

int main(){
  cout << "Welcome to Event Planner!" << endl;
  
  char choice = 'a';

  do {
    cout << " " << endl;
    cout << "-----------------------" << endl;
    cout << "Select an event to plan." << endl;
    cout << "1 - Beach Trip" << endl;
    cout << "2 - Shopping Trip" << endl;
    cout << "3 - Restaurant" << endl;
    cout << "q - quit program" << endl;
    cin >> choice;
    cin.ignore(1000, '\n');

    //beach
    if(choice == '1'){
      int a = 0;
      string word;
      char food[150];
      char dir[500];
      vector<string> vtr;
      char yn[5];
      cout << "Enter the amount of items you would like to " << endl;
      cout << "add to the list of things to bring to the beach" << endl;
      cout << "> ";
      cin >> a;
      cin.ignore(1000, '\n');
      cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

      for(int i = 0; i < a; i++){
	cout << "> ";
	getline(cin, word);
	vtr.push_back(word);
      }
      cout << "Please enter what you plan to do for food (go out, bring lunch, etc)." << endl;
      cout << "> ";
      cin.get(food, 150);
      cin.get();
      cout << "Enter the directions to the beach: " << endl;
      cout << "> ";
      cin.get(dir, 500);
      cin.get();
      Beach b(vtr, dir, food);
      cout << "Would you like to change any fields or look at more beach options? (y/n)" << endl;
      cout << "> ";
      cin.get(yn, 5);
      cin.get();
      if(strcmp(yn, "y") == 0){
	beach(b);
      }
    }
    
    //shopping
    else if (choice == '2'){
      int a = 0;
      int b = 0;
      string word;
      string item;
      vector<string> shops;
      vector<string> items;
      int bg;
      char yn[5];

      cout << "Enter the amount of stores you would like to visit." << endl;
      cin >> a;
      cin.get();
      cout << "Enter each store in 1 at a time, separated by a newline." << endl;
      for(int i = 0; i < a; i++){
	cout << "> ";
	getline(cin, word);
	shops.push_back(word);
      }
      
      cout << "Enter the amount of items you would like to add to your shopping list." << endl;
      cin >> b;
      cin.get();
      cout << "Enter each item in 1 at a time, separated by a newline." << endl;
      for(int j = 0; j < b; j++){
	cout << "> ";
	getline(cin, item);
	items.push_back(item);
      }

      cout << "What is your budget for this shopping trip?" << endl;
      cout << "> ";
      cin >> bg;
      cin.get();

      Shopping s(shops, items, bg);
      cout << "Would you like to change any fields or look at more shopping options? (y/n)" << endl;
      cout << "> ";
      cin.get(yn, 5);
      cin.get();
      if(strcmp(yn, "y") == 0){
	shopping(s);
      }
    }

    //restaurant
    else if(choice == '3'){
      Restaurant r;
      char yn[5];
      r.read();
      cout << "Would you like to change or view more restaurant options? (y/n)" << endl;
      cout << "> ";
      cin.get(yn, 5);
      cin.get();
      if(strcmp(yn, "y") == 0){
	restaurant(r);
      }
    }
  } while(choice != 'q'); 
  
  
  return 0;
}

void beach(Beach & b){
  char choice;
  string word;
  int amount;
  vector<string> to_add;
  vector<string> to_remove;

  cout << "Select an option." << endl;
  cout << "1 - add items to bring to the beach " << endl;
  cout << "2 - remove from the list of items to bring" << endl;
  cout << "3 - display your current beach trip details" << endl;
  cout << "4 - check the weather at the beach" << endl;
  cin >> choice;
  cin.ignore(1000, '\n');

  //add items
  if (choice == 1){
    cout << "how many items would you like to add?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_add.push_back(word);
    }    
  }

  //remove items
  else if (choice == 2){
    cout << "how many items would you like to remove?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_remove.push_back(word);
    }    
  }

  //display
  else if (choice == 3){
    b.display();
  }

  //check weather
  else if (choice == 4){
    b.check_weather();
  } else {
    cout << "That was not one of the options." << endl;
  }
  
}

void shopping(Shopping & s){
  char i;
  vector<string> to_add1;
  vector<string> to_remove1;
  vector<string> to_add2;
  vector<string> to_remove2;
  int amount;
  string word;
  
  cout << "Select an option." << endl;
  cout << "1 - Add stores to the list. " << endl;
  cout << "2 - Remove stores from the list." << endl;
  cout << "3 - Add items to your shopping list. " << endl;
  cout << "4 - Remove items from your shopping list." << endl;
  cout << "5 - Display all details of your shopping trip." << endl;
  cout << "> ";
  cin >> i;
  cin.get();

  if(i == '1'){
    cout << "how many stores would you like to add?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each store (1 at a time, separated by a newline)" << endl;
    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_add1.push_back(word);
    }    
    s.add_stores(to_add1);
  }

  else if(i == '2'){
    cout << "how many stores would you like to remove?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each store (1 at a time, separated by a newline)" << endl;
    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_remove1.push_back(word);
    }    
    s.remove_stores(to_remove1);
  }

  else if(i == '3'){
    cout << "how many items would you like to add?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_add2.push_back(word);
    }
    s.add_items(to_add2);
  }

  else if(i == '4'){
    cout << "how many items would you like to remove?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;
    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_remove2.push_back(word);
    }    
    s.remove_items(to_remove2);
  }

  else if(i == '5'){
    s.display();
  }
}

void restaurant(Restaurant & r){
  char c;
  
  cout << "Select an option." << endl;
  cout << "1 - Get the contact info of the restaurant." << endl;
  cout << "2 - Write a yelp review of this restaurant." << endl;
  cout << "3 - Display all restaurant details." << endl;
  cout << "> ";
  cin >> c;
  cin.get();
  if(c == '1'){
    r.contact_info();
  } else if (c == '2'){
    r.write_yelp_review();
  } else if (c == '3'){
    r.display();
  }
  
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             