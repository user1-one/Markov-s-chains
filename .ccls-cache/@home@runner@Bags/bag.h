#ifndef BAG_H
#define BAG_H

#include <vector>
#include <iostream>
#include "random.h"
using namespace std;

// "T" is out parameterized type that we're making a bag out of
// Whenever you see "T", that means "the type of the elements of the bag"
template <typename T>
class Bag{
 public: 

  Bag(); // default constructor

  // functions to get information about the bag
  int size() const;
  int count(const T& item) const;
  bool is_empty() const;
  void Display() const;
  
  // we'll talk about choose in the lab
  bool Choose(T& random);
  // fuctions to modify the bag
  void insert(const T& item);
  bool remove(const T& item); // returns true if successful, false otherwise

 
 private: 

  vector<T> bag_elements;
};




// Since this is a template class, we need to write the implementations of the
// member functions here, in the .h file.


// default constructor, initializes the vector to be empty
template <typename T>
Bag<T>::Bag(){
  bag_elements.resize(0);
}

// size function: returns the number of elements currently in the bag
template <typename T>
int Bag<T>::size() const{
  return bag_elements.size();
}

// count function: returns the number of elements that are equal to "item"
template <typename T>
int Bag<T>::count(const T& item) const{
  int num_matches = 0;
  for(int i = 0; i < bag_elements.size(); i++)
    if(bag_elements[i] == item)
      num_matches++;

  return num_matches;
}

// is_empty: returns true if the bag has 0 elements, false otherwise
template <typename T>
bool Bag<T>::is_empty() const{
  return (size() == 0);
}

// insert: adds "item" to the bag by adding the new item to the private vector
template <typename T>
void Bag<T>::insert(const T& item){
  bag_elements.push_back(item);
}

// remove: removes one occurrence of "item" from the bag, if it exists
// returns true if there was an item removed, false if not
template <typename T>
bool Bag<T>::remove(const T& item){
  bool found = false;
  int i = 0;
  while(!found && i <bag_elements.size()){
    if(bag_elements[i] == item)
      found = true;
    else
      i++;
  }
  
  if(found){
    bag_elements[i] = bag_elements[bag_elements.size()-1];
    bag_elements.resize(bag_elements.size()-1);
  }
  return found;
}
template <typename T>
void Bag<T>::Display() const{
  for(int i=0; i< bag_elements.size(); i++){
    cout<<bag_elements[i]<<" | ";
  }
}
template <typename T>
bool Bag<T>:: Choose(T& random) {
  if(bag_elements.size()>0)
 random= bag_elements[Draw(0, bag_elements.size()-1)];
  return (bag_elements.size() > 0);
}
    
#endif


