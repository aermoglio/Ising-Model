#include <iostream>
#include <string>
#include <time.h> 
#include <cstdlib> 
#include "atomchain.h"
#include "montecarlo.h"

using namespace std;

int main() {
    srand(time(0));      // uses current time as the seed so all values produced for the states are different.

    int N = 100;
    int iterations = 50000;
    double T=100;
    AtomChain chain(N);
    
    std::cout << "Initial Atom Chain: " << std::endl;
    chain.printChain();
    
    MonteCarlo (chain,N,T,iterations);

    std::cout << "Final Atom Chain: " << std::endl;
    chain.printChain();

    return 0;
}