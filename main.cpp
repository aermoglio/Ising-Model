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

    // setting parameters
    int n_configurations = 10000;  
    int N= 100;
    int iterations=100000;
    double T=3.5;

    // creating headers for outfile
    ofstream outfile("output2D.txt");
    outfile<<"Number of Configurations: "<<n_configurations<<endl; 
    outfile<<"Number of Atoms: "<<N<<endl; 
    outfile<<"Monte Carlo Iterations: "<<iterations<<endl; 
    outfile<<"Temperature: "<<T<<endl; 
    
    outfile<<"Configuration "<<"TotalEnergy "<<"Magnetisation "<<endl; 
    
    // performing Monte carlo algorithm and saving results to a file
    for (int n=0;n<n_configurations;n++){
        AtomGrid grid(N);
        
        MonteCarlo (grid,N,T,iterations);  
        outfile<<n<<" "<< grid.totalEnergy() <<" "<<grid.totalMagnetisation()<<endl;  
    }

    outfile.close();
    return 0;
}