#include "bag.h"
#include "markov.h"
#include "random.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
void print_vector(const vector<string> &a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << "|";
  }
}
void print_markov(const vector<MarkovEntries> &a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i].Get_String() << "|";
  }
}
int pos_finder(vector<MarkovEntries> a, string x) {
  for (int i = 0; i < a.size(); i++) {
    if (a[i].Get_String() == x) {
      return i;
    }
  }
  return -1;
}
int main() {

  Init_RNG(1);
  vector<MarkovEntries> text;
  vector<string> input;
  string filename;
  cout << " File name: ";
  cin >> filename;
  ifstream fin;
  fin.open(filename.data());

  while (!fin.eof()) {
    string temp;
    fin >> temp;
    input.push_back(temp);
  }
  fin.close();

  // march through the input
  for (int j = 0; j < input.size()-1; j++) {
    bool found = false;
    // march through the markoventries so far
    for (int i = 0; i < text.size(); i++) {
      // if the word is seen before insert the successor to the bag of that word
      if (input[j] == text[i].Get_String()) {
        text[i].insert_successor(input[j + 1]);
        found = true;
      }
      
    }
    // if it is not found then add it to the vector
    if (!found) {
      MarkovEntries temp(input[j]);
     temp.insert_successor(input[j + 1]);
      text.push_back(temp);
      
    }
  }
  
  int count = 0;
  cout << "\n How many words do you want to generate? \n";
  cin >> count;
  // start from a random markov entry
  int i = Draw(0, text.size() - 1);
  // generate words until count is reached!
  
  for (int j = 0; j < count; j++) {
    // pick a word print it
      cout << text[i].Get_String()<<" ";
    // choose a random successor print it
    string choice = "A";
    if (text[i].ChooseSuccessor(choice)) {
      i = pos_finder(text, choice);
    }
    // if we hit the last element and there is no successor then redraw a random
    // element
    else {
      i = Draw(0, text.size() - 1);
    }
    //now find text[i]'s successor until count is reached
  }
  
}