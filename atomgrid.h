#ifndef ATOMGRID_H
#define ATOMGRID_H

#include <vector> 
#include <iostream>
#include <string>
#include <cmath>
#include "atom.h"


using namespace std; 

class AtomGrid{         // replaced the atomchain class with an atomgrid
    public:
        AtomGrid(int N);
        int N;         
        vector<vector<Atom>> atoms;            // similar process to before, created a vector (in this case a vector of vectors) to populate with Atom objects
        Atom& getAtom(int row, int col);     // function to select an element from the vector
        void printGrid();        // function to print the grid 
 
        double totalEnergy();         // functions to calculate the total energy of the frid and the magnetisation
        double totalMagnetisation();
    
};

#endif
