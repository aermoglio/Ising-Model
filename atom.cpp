#include "atom.h"
#include <cmath>
#include <time.h> 
#include <cstdlib> 

Atom::Atom(){
    srand(time(0));                     // using current time as seed for random number generator
    state = (rand() % 2 == 0) ? -1 : 1; // randomly assigning the atom a value of -1 or 1
}

int Atom::getState(){
    return state;

}
