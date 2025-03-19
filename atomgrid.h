#ifndef ATOMGRID_H
#define ATOMGRID_H

#include <vector> 
#include <iostream>
#include <string>
#include <cmath>
#include "atom.h"


using namespace std; 

class AtomGrid{
    public:
        AtomGrid(int N);
        int N;
        vector<vector<Atom>> atoms;
        Atom& getAtom(int row, int col); 
        void printGrid();

        double totalEnergy();
        double totalMagnetisation();
    
};

#endif
