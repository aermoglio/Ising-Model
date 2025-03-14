#include "montecarlo.h"
#include <iostream>

using namespace std;

int computeEnergyChange(AtomChain &chain,int N, int index){
    int energyChange =0;

    int selectedState =chain.getAtom(index).getState();
    int leftNeighbour, rightNeighbour;
    // finding neighbours
    // consider situation at boundaries:
    if (index==0){
        rightNeighbour = chain.getAtom (index+1).getState();
        leftNeighbour = 0;
    }
    if (index==N-1){
        leftNeighbour = chain.getAtom(index-1).getState();
        rightNeighbour = 0;
    }
    // in general:
    else {
        leftNeighbour = chain.getAtom(index-1).getState();
        rightNeighbour = chain.getAtom (index+1).getState();
    }

    energyChange = -(selectedState*leftNeighbour)-(selectedState*rightNeighbour);
    return energyChange;

}

void MonteCarlo(AtomChain &chain,int N, int iterations){
    // calculate the energy change of that combination
    for (int i=0;i<iterations;i++){
        
        int randomIndex=rand()% N;   // picking a random atom from the chain
        Atom& selectedAtom =chain.getAtom(randomIndex);

        computeEnergyChange(chain, N,randomIndex);
        
        //applying conditions for energy:
        

        // picking t random atom and flipping the state
       //  
        //selectedAtom.flip();

        // calculating the change in energy ocurring from this flip (considering neighbouring atoms)


    }


}

