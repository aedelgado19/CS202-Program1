/* Author: Allison Delgado
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
