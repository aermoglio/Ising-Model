#ifndef ATOMCHAIN_H
#define ATOMCHAIN_H

#include <vector> 
#include <iostream>
#include <string>
#include <cmath>
#include "atom.h"

using namespace std; 

class AtomChain{
    public:
        AtomChain(int N);              //constructor to create a chain of atoms
        int N;
        vector<Atom> atoms;       // creating vector of 100 elements. this is our atom chain

};

#endif