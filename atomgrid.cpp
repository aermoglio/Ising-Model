#include <iostream>
#include "atomgrid.h"
#include "atom.h"


AtomGrid::AtomGrid(int N){
    this-> N = N;
    this->atoms.resize(N, vector<Atom>(N));       // resizing the atoms vector to become an NxN grid

    for (int i = 0;i < N;i++) {
        for (int j = 0; j < N; j++) {
            this->atoms[i][j] = Atom();      // populating the grid with atoms.
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

double AtomGrid::totalEnergy(){                      // calculating total energy while considering boundary conditions
    int energy =0;
    for (int i =0; i<N; i++){
        for (int j=0;j<N;j++){
            int selectedAtom=atoms[i][j].getState();
            if (j< N - 1){
                energy += -selectedAtom * atoms[i][j + 1].getState();
            } 
            if (i < N - 1) {
                energy += -selectedAtom * atoms[i + 1][j].getState(); 
        }
    }
}
    return energy;
}

double AtomGrid::totalMagnetisation(){           // summing the spins to obtain magnetisation
    int magnetisation =0;
    for (int i =0; i<N; i++){
        for (int j=0;j<N;j++){
            magnetisation+=atoms[i][j].getState();
    }} 
    return magnetisation;
}

