#include <iostream>
#include <string>
#include "bag.h"
#include "random.h"
#include "markov.h"
#include <vector>
#include <fstream>
#include <string>
using namespace std;
void print_vector(vector<string> a){
  for(int i=0; i< a.size(); i++){
    cout<<a[i]<<" | ";
  }
}
int pos_finder(vector<MarkovEntries> a, string x){
  for(int i=0; i< a.size(); i++){
    if(a[i].Get_String()==x){
      return i;
    }
  }
  return -1;
}
int main(){
  
  Init_RNG (-1);
  vector<MarkovEntries> text;
  vector <string> input;
  string filename;
    cout << " File name: ";
    cin >> filename;
    ifstream fin;
    fin.open(filename.data());
  
  while(!fin.eof()){
  string temp;
  fin>>temp;
    input.push_back(temp);
    }
  fin.close();
print_vector(input);
 //march through the input  
for(int j=0; j<input.size();j++){
  //march through the markoventries so far
  for(int i=0; i< text.size(); i++){
   // if the word is seen before insert the successor to the bag of that word 
  if(input[j] == text[i].Get_String()){
    text[i].insert(input[j+1]);
  }
    }
  // if it is not found then add it to the vector 
  text.push_back(MarkovEntries(input[j]));

  }
  int count=0;
  cout<<"How many words do you want to generate? \n";
  cin>>count;
  //start from a random markov entry
  int i=Draw(0,text.size()-1);
  //generate words until count is reached!
  for(int j=0; j<= count; j++){
  //pick a word print it
  MarkovEntries temp1=text[i];
  cout<<temp1.Get_String();
  //choose a random successor print it 
  string choice="A";
  if(temp1.ChooseSuccessor(choice)){
    i= pos_finder(text,choice);
    }
  // if we hit the last element and there is no successor then redraw a random element
  else{
    i= Draw(0,text.size()-1);
  }
    }
  // find the successors markov entry then choose a successor for it
  //print it then randomly choose a successor
  // find the its entry choose a successor and print it
  // repeat until you have printed n strings
  
  }