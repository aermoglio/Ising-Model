#include <iostream>
#include <string>
#include <time.h> 
#include <fstream>
#include <cstdlib> 
#include "atomchain.h"
#include "atom.h"
#include "montecarlo.h"

using namespace std;

int main() {
    int n_configurations = 10000;        // number of configurations to create
    
    ofstream outfile("output1D.txt");   //creating file for output

    
    int N = 100;          // number of particles
    int iterations = 10000;    //number of iterations for monte carlo
    double T=3.5;        // we set k at 1, so our units for temperature have now changed to being dimensionless;

    srand(time(0));      // uses current time as the seed so all values produced for the states are different.
    
    // parameters onto output file
    outfile<<"Number of Configurations: "<<n_configurations<<endl; 
    outfile<<"Number of Atoms: "<<N<<endl; 
    outfile<<"Monte Carlo Iterations: "<<iterations<<endl; 
    outfile<<"Temperature: "<<T<<endl; 

    outfile<<"Configuration "<<"TotalEnergy "<<"Magnetisation "<<endl;   // output file header
    for (int n=0;n<n_configurations;n++){

        AtomChain chain(N);    //creating an object of class AtomChain
        
        MonteCarlo (chain,N,T,iterations);     //performing monte carlo on chain
        // results are appended onto a file
        outfile<<n<<" "<< chain.totalEnergy() <<" "<<chain.totalMagnetisation()<<endl;    // output onto file

    }
    outfile.close();
    return 0;
}