
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

Atom& AtomChain::getAtom(int index) {
    return atoms[index];

}

// functions to calculate total energy and magnetisation
//double AtomChain::totalEnergy(){

//}

double AtomChain::totalMagnetisation(){
    int magnetisation=0;
    for (int i=0; i<N; i++){
        magnetisation+=atoms[i].getState();
    }
    return magnetisation;


}


