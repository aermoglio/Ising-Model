#include <iostream>
#include <string>
#include <time.h> 
#include <fstream>
#include <cstdlib> 
#include "atomgrid.h"
#include "atom.h"
#include "montecarlo.h"

using namespace std;

int main() {
    srand(time(0));  

    int n_configurations = 10000;  
    int N= 100;
    int iterations=10000;
    double T_min = 0.1, T_max = 5;
    double T_step = 0.1;

    ofstream energyFile("energy_vs_temperature2D.txt");
    ofstream magFile("magnetisation_vs_temperature2D.txt");
    
    energyFile << "Temperature " << "AverageEnergy" << endl;
    magFile << "Temperature " << "AverageMagnetisation" << endl;
    
    for (double T = T_min; T <= T_max; T += T_step) {
        double total_energy = 0.0;
        double total_magnetisation = 0.0;

        for (int n = 0; n < n_configurations; n++) {
            AtomGrid grid(N); 
            
            MonteCarlo(grid, N, T, iterations); 

            total_energy += grid.totalEnergy();
            total_magnetisation += fabs(grid.totalMagnetisation());
        }

        double avg_energy = total_energy / n_configurations;
        double avg_magnetisation = total_magnetisation / n_configurations;

        energyFile << T << " " << avg_energy << endl;
        magFile << T << " " << avg_magnetisation << endl;
    }

    energyFile.close();
    magFile.close();
    return 0;
}