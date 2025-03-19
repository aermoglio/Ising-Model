#include <iostream>
#include "atomgrid.h"
#include "atom.h"


AtomGrid::AtomGrid(int N){
    this-> N = N;
    this->atoms.resize(N, vector<Atom>(N)); 

    for (int i = 0;i < N;i++) {
        for (int j = 0; j < N; j++) {
            this->atoms[i][j] = Atom();
        }
}
}

void AtomGrid::printGrid() {
    
    for (vector<Atom>& row : atoms) {
        for (Atom& atom : row) { 
            cout << atom.getState() << " ";
    }
    cout << endl;
}
}

Atom& AtomGrid::getAtom(int row,int col) {            // function to pick an element from our atoms chain
    return atoms[row][col];
}


// to do: total energy
// to do magnetisation
