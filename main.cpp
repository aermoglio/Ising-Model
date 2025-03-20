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
    int n_configurations = 1000;        // number of configurations to create

    int N = 3;          // number of particles
    int iterations = 25000;    //number of iterations for monte carlo
    // for this, we want to test a range of temperatures
    double T_min=0.1, T_max=100;
    double T_step=1;        //

    ofstream energyFile("energy_vs_temperature1D.txt");
    ofstream magFile("magnetisation_vs_temperature1D.txt");
   
    srand(time(0));      // uses current time as the seed so all values produced for the states are different.
    
    // Headers for file
    energyFile<<"Temperature "<<"Average Energy"<<endl; 
    magFile<<"Temperature "<<"Average Magnetistation"<<endl;

    for (double T = T_min; T <= T_max; T += T_step){
        double total_energy = 0.0;
        double total_magnetisation = 0.0;

        for (int n=0;n<n_configurations;n++){

            AtomChain chain(N);    //creating an object of class AtomChain
            
            MonteCarlo (chain,N,T,iterations); 

            total_energy += chain.totalEnergy();
            total_magnetisation += chain.totalMagnetisation();

        }
        double avg_energy = total_energy / n_configurations;
        double avg_magnetisation = total_magnetisation / n_configurations;

        energyFile << T << " " << avg_energy << endl;
        magFile << T << " " << avg_magnetisation << endl;

      // output onto file

    }
    energyFile.close();
    magFile.close();
    return 0;
}