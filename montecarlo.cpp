#include "montecarlo.h"
#include <iostream>

using namespace std;

void MonteCarlo(AtomChain &chain,int N, int iterations){
    // calculate the energy change of that combination
    int randomIndex=rand()% N;
    Atom& selectedAtom =chain.getAtom(randomIndex);
    selectedAtom.flip();

    cout << "Flipped atom at index " << randomIndex 
    << " -> New state: " << selectedAtom.getState() << endl;

}

