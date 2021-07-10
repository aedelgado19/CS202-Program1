/* Author: Allison Delgado
   Class: CS202 Summer 2021
   The main class acts as a testing site for
   all public member functions in the classes.
   The aim of this program is to act as a scheduling
   tool for various tasks.

   Last updated: July 5, 2021
 */

#include <iostream>
#include "Event.h"
using namespace std;

int main(){
  cout << "Welcome to Event Planner!" << endl;

  
  Beach b;
  Restaurant r;
  Shopping s;
  
  
  char choice = 'a';
  
  do {
    cout << "Select an event to plan." << endl;
    cout << "1 - Beach Trip" << endl;
    cout << "2 - Shopping Trip" << endl;
    cout << "3 - Restaurant" << endl;
    cout << "q - quit program" << endl;
    cin >> choice;
    cin.ignore(1000, '\n');
  } while(choice != 'q'); 
  
  
  return 0;
}
