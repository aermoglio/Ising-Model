#include "montecarlo.h"
#include <iostream>

using namespace std;

int computeEnergyChange(AtomChain &chain,int N, int index){
    int energyChange =0;

    int selectedState =chain.getAtom(index).getState();
    int flippedState= - selectedState;
    int leftNeighbour, rightNeighbour;
    // finding neighbours
    // consider situation at boundaries:
    if (index==0){
        rightNeighbour = chain.getAtom(index+1).getState();
        leftNeighbour = 0;
    }
    else if (index==N-1){
        leftNeighbour = chain.getAtom(index-1).getState();
        rightNeighbour = 0;
    }
    // in general:
    else {
        leftNeighbour = chain.getAtom(index-1).getState();
        rightNeighbour = chain.getAtom (index+1).getState();
    }

    // calculating energy change
    // before and afterflipping:
    int energyBefore=-selectedState*(leftNeighbour+rightNeighbour);
    int energyAfter=-flippedState*(leftNeighbour+rightNeighbour);
    // change in energy:
    energyChange = energyAfter-energyBefore;
    return energyChange;

}

void MonteCarlo(AtomChain &chain,int N, double T, int iterations){
    // calculate the energy change of that combination
    for (int i=0;i<iterations;i++){
        
        int randomIndex=rand()% N;   // picking a random atom from the chain
        Atom& selectedAtom =chain.getAtom(randomIndex);

        double energyChange = computeEnergyChange(chain, N,randomIndex);
        
        //calculating P:
        double k = 1;    // setting boltzmann to 1
        double beta = 1/(k*T);
        double P = exp(-beta*energyChange);

        //condition if P>1
        if (P>1){
            P=1;
        }

        double randomValue = ((rand()%1000)/1e4);    // generate random value between 0 and 1

        if (randomValue<P){
            selectedAtom.flip();
        }

    }


}

