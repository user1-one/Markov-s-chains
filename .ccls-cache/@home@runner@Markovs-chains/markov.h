#ifndef MARKOV_H
#define MARKOV_H

#include <vector>
#include <iostream>
#include "random.h"
#include "bag.h"
using namespace std;


// "T" is out parameterized type that we're making a bag out of
// Whenever you see "T", that means "the type of the elements of the bag"

class MarkovEntries{
 public: 

   MarkovEntries(string item); // default constructor

  // functions to get information 
  int size() const;
  
  bool is_empty() const;
  bool ChooseSuccessor(string& choice);
  Bag<string> Get_Successors();
  void Display_Successors() const;
  string Get_String() const;
  // 
  void insert(string successor);
  
 private: 

  string Markov;
  Bag<string> MarkovChains;
};
#endif


