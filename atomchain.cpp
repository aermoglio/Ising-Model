
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
void AtomChain::totalEnergy(){
    int energy =0;
    for (int i =0;i<N;i++){
        if (i==0){
            energy+=-atoms[i].getState()*atoms[i+1].getState();
        }
        else if (i==N-1){
            energy+=-atoms[i].getState()*atoms[i-1].getState();
        }
        else{
            energy+=-atoms[i].getState()*(atoms[i-1].getState()+atoms[i+1].getState());
        }
    } double totalEnergy=energy/2;
    cout << "Total Energy: " << totalEnergy << endl;
}

void AtomChain::totalMagnetisation(){
    int magnetisation=0;
    for (int i=0; i<N; i++){
        magnetisation+=atoms[i].getState();
    }    
    cout << "Total Magnetisation: " << magnetisation << endl;
}


