
#include "atomchain.h"


AtomChain::AtomChain(int N){
    this-> N = N;
    this-> atoms.resize(this->N);   // resizing the atoms vector to have N components
}

void AtomChain::printChain() {
    for (Atom &atom : this->atoms) {        // for each element in the atoms vector, obtain the state and return it
        cout << atom.getState() << " ";
    }
    cout << endl;
}