#ifndef MARKOV_H
#define MARKOV_H

#include <vector>
#include <iostream>
#include "random.h"
#include "bag.h"
#include <string>
using namespace std;


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
  void insert_successor(string successor);
  
 private: 

  string Markov;
  Bag<string> MarkovChains;
};
#endif


