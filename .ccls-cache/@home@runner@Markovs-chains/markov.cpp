#include "markov.h"
#include <vector>
#include "random.h"
#include "bag.h"
#include <string>
using namespace std;

// default constructor, initializes the vector to be empty

MarkovEntries::MarkovEntries(string item){
   Markov= item;
}
int MarkovEntries::size() const{
  return MarkovChains.size();
}
// is_empty: returns true if the bag of successors has 0 elements, false otherwise
bool MarkovEntries::is_empty() const{
  return (size() == 0);
}

// insert: adds "item" to the bag by adding the new item to the private vector

void MarkovEntries::insert(string successor){
  MarkovChains.insert(successor);
}
bool MarkovEntries::ChooseSuccessor(string& choice) {
  return MarkovChains.Choose(choice);
  
}

void MarkovEntries::Display_Successors() const{
  MarkovChains.Display();
}
 
string MarkovEntries:: Get_String() const{
  return Markov;
}