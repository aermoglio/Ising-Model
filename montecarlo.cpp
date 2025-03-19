#include "montecarlo.h"
#include <iostream>

using namespace std;

int computeEnergyChange(AtomGrid &grid,int N, int row, int col){   // function to calculate change in energy if a randomly chosen atom were to be flipped
    double energyChange =0;

    int selectedState =grid.getAtom(row, col).getState();       // obtaining the state of the selected atom (chosen using a RNG for the index)
    
    int flippedState= - selectedState;                     // considering what the flipped state of the chosen atom would be
    int leftNeighbour=0, rightNeighbour=0, topNeighbour=0, bottomNeighbour=0;          // defining variables for our selected atom's neighbours
    
    // FINDING NEIGHBOUR STATES
    // consider situation at boundaries:

    if (col> 0) leftNeighbour = grid.getAtom(row, col-1).getState();
    if (col< N - 1) rightNeighbour = grid.getAtom(row, col+1).getState();
    if (row> 0) topNeighbour = grid.getAtom(row - 1, col).getState();
    if (row< N - 1) bottomNeighbour = grid.getAtom(row + 1, col).getState();
  
    // CALCULATING ENERGY CHANGE IF ATOM WERE TO FLIP

    // before and after flipping:
    double energyBefore= -selectedState*(leftNeighbour+rightNeighbour+topNeighbour+bottomNeighbour);
    double energyAfter= -flippedState*(leftNeighbour+rightNeighbour+topNeighbour+bottomNeighbour);
    energyChange=energyBefore-energyAfter;
    // change in energy:

    return energyChange;

}

// MONTE CARLO
void MonteCarlo(AtomGrid &grid,int N, double T, int iterations){             

    for (int i=0;i<iterations;i++){
        
        int randomRow=rand()% N;   // picking a random row from the grid
        int randomCol=rand()% N;   // picking a random atom from the chain
        
        Atom& selectedAtom =grid.getAtom(randomRow,randomCol);          // getting the state of our randomly selected atom

        double energyChange = computeEnergyChange(grid, N,randomRow,randomCol);           // calculating energy change if our selected atom were to be flipped
        
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

