#include "atom.h"
#include <cmath>
#include <cstdlib> 

Atom::Atom(){
    state = (rand() % 2 == 0) ? -1 : 1; // randomly assigning the atom a value of -1 or 1
}

int Atom::getState() {
    return state;
}

void Atom::flip(){
    state = -state;  
}
