#include "montecarlo.h"
#include <iostream>

using namespace std;

void MonteCarlo(AtomChain &chain,int N, int iterations){
    // calculate the energy change of that combination
    for (int i=0;i<iterations;i++){
        int randomIndex=rand()% N;
        Atom& selectedAtom =chain.getAtom(randomIndex);
        selectedAtom.flip();
    }


}

