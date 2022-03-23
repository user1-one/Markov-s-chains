#include <iostream>
#include <string>
#include "bag.h"

using namespace std;

int main(){
  Bag<string> my_bag;
  
  cout << "How many elements in the bag? ";
  int bag_size;
  cin >> bag_size;
  
  for(int i = 0; i < bag_size; i++){
    cout << "Enter bag element # " << i+1 << ": ";
    string item;
    cin >> item;
    my_bag.insert(item);
  }
/*
  cout << "The bag now has " << my_bag.size() << " elements" << endl;
  cout << "Which element should we count?";
  string item;
  cin >> item;
  cout << "That item appears " << my_bag.count(item) << " times "<< endl;
  */
//my_bag.Display(); 
cout<<my_bag.Choose();
  return 0;
}
