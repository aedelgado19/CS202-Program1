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

Time::Time(){

}

Time::~Time(){

}

void Time::read(){

}

void Time::display(){

}

void Time::compare(){

}

//******************* EVENT FUNCTIONS *****************

Event::Event(){

}

Event::~Event(){

}

Event::Event(const Event & source){

}

void Event::read(){

}

void Event::fun_fact(){

}

void Event::display(){

}

//******************* BEACH FUNCTIONS *****************
Beach::Beach(){

}

Beach::~Beach(){

}

Beach::Beach(const Beach & source){

}

Beach::Beach(std::vector<std::string> items, char* directions, std::string food){

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
