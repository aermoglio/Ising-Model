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
        void printChain();      // member function used for debugging (to actually print and see the chain)
        Atom& getAtom(int index);          // this refers to an object of the Atom class within the chain. used to select a specific atom from the chain

        // functions to calculate total energy and magnetisation
        void totalEnergy();
        void totalMagnetisation();

};

#endif