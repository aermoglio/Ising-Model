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

    int N = 100;          // number of particles
    int iterations = 10000;    //number of iterations for monte carlo
    // for this, we want to test a range of temperatures
    double T_min=0.01, T_max=5;
    double T_step=0.1;        //

    //output now into two files, one for magnetisation and one for energy
    ofstream energyFile("energy_vs_temperature1D.txt");
    ofstream magFile("magnetisation_vs_temperature1D.txt");
   
    srand(time(0));      // uses current time as the seed so all values produced for the states are different.
    
    // headers
    // in this case, the process is similar as in the main branch, except that the avg energy and avg magnetisation are saved in a file for a range of temperatures
    energyFile<<"Temperature "<<"AverageEnergy"<<endl; 
    magFile<<"Temperature "<<"AverageMagnetisation"<<endl;

    for (double T = T_min; T <= T_max; T += T_step){
        double total_energy = 0.0;
        double total_magnetisation = 0.0;

        for (int n=0;n<n_configurations;n++){

            AtomChain chain(N);    //creating an object of class AtomChain
            
            MonteCarlo (chain,N,T,iterations); 

            total_energy += chain.totalEnergy();
            total_magnetisation += fabs(chain.totalMagnetisation());

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