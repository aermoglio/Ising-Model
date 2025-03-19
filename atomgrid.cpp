#include <iostream>
#include "atomgrid.h"
#include "atom.h"


AtomGrid::AtomGrid(int N){
    this-> N = N;
    this-> atoms.resize(this->N, vector<Atom>(this->N));
}

