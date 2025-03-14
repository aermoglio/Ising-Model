
#include "atomchain.h"


AtomChain::AtomChain(int N){
    this-> N = N;
    this-> atoms.resize(this->N);   // resizing the atoms vector to have N components
}

void AtomChain::printChain() {
    for (Atom &atom : this->atoms) {
        cout << atom.getState() << " ";
    }
    cout << endl;
}