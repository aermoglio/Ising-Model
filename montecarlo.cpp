#include "montecarlo.h"
#include <iostream>

using namespace std;

int computeEnergyChange(AtomChain &chain,int N, int index){   // function to calculate change in energy if a randomly chosen atom were to be flipped
    int energyChange =0;

    int selectedState =chain.getAtom(index).getState();       // obtaining the state of the selected atom (chosen using a RNG for the index)
    int flippedState= - selectedState;                     // considering what the flipped state of the chosen atom would be
    int leftNeighbour, rightNeighbour;               // defining variables for our selected atom's neighbours
    
    // FINDING NEIGHBOUR STATES
    // consider situation at boundaries:
    if (index==0){                                           // first atom in chain has no neighbours to the left
        rightNeighbour = chain.getAtom(index+1).getState();
        leftNeighbour = 0;
    }
    else if (index==N-1){                                   // final atom in chain has no neighbours on right
        leftNeighbour = chain.getAtom(index-1).getState();
        rightNeighbour = 0;
    }
    // in general:
    else {                                                   // getting the state of the neighbour atoms based on index
        leftNeighbour = chain.getAtom(index-1).getState();
        rightNeighbour = chain.getAtom (index+1).getState();
    }

    // CALCULATING ENERGY CHANGE IF ATOM WERE TO FLIP

    // before and after flipping:
    int energyBefore=-selectedState*(leftNeighbour+rightNeighbour);
    int energyAfter=-flippedState*(leftNeighbour+rightNeighbour);
    
    // change in energy:
    energyChange = energyAfter-energyBefore;
    return energyChange;

}

// MONTE CARLO
void MonteCarlo(AtomChain &chain,int N, double T, int iterations){             
    // calculate the energy change of that combination
    for (int i=0;i<iterations;i++){
        
        int randomIndex=rand()% N;   // picking a random atom from the chain
        Atom& selectedAtom =chain.getAtom(randomIndex);          // getting the state of our randomly selected atom

        double energyChange = computeEnergyChange(chain, N,randomIndex);           // calculating energy change if our selected atom were to be flipped
        
        //calculating probability:
        double k = 1;    // setting boltzmann to 1, for simplicity purposes
        double beta = 1/(k*T);
        double P = exp(-beta*energyChange);

        //condition if P>1
        if (P>1){
            P=1;
        }

        double randomValue = ((rand()%1000)/1e4);    // generate random value between 0 and 1

        // accepting/refusing values. if the generated random value is below P, then the atom will flip
        if (randomValue<P){
            selectedAtom.flip();
        }

    }


}

