#include <iostream>
#include <string>
#include <time.h> 
#include <cstdlib> 
#include "atomchain.h"
#include "atom.h"
#include "montecarlo.h"

using namespace std;

int main() {
    srand(time(0));      // uses current time as the seed so all values produced for the states are different.

    int N = 100;
    int iterations = 50000;
    double T=0.0128;        //temperature might be in electronvolts? we set k at 1;
    AtomChain chain(N);
    
    cout << "Initial Atom Chain: " << endl;
    chain.printChain();
    
    MonteCarlo (chain,N,T,iterations);

    cout << "Final Atom Chain: " << endl;
    chain.printChain();
    
    chain.totalEnergy();
    chain.totalMagnetisation();

    return 0;
}