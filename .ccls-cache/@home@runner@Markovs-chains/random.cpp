#include "random.h"
#include <ctime>
#include <cstdlib>
using namespace std;
//call random numbers

// <=0 picks a sequence based on the time.  Any other nuumber gives a fixed
// sequence of random numbers
void Init_RNG(int seed){
    if(seed<=0){
        srand(time(0));
    }
    else{
        srand(seed);
    }
}

//draw in a random number between high and low
int Draw(int low, int high){
    int get_num = ((rand() % (high-low+1)) + low);
    return get_num;
}

//Draws two numbers between 1 and 6 and adds them together
int Two_Dice(){
  return Draw(1,6) + Draw(1,6);
}
