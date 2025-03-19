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

    int N= 10;
    int iterations=50000;
    double T=0.9;

    AtomGrid grid(N);
    grid.printGrid();

    cout<<"New!"<<endl;

    MonteCarlo (grid,N,T,iterations);  
    grid.printGrid();

   // int n_configurations = 10000;        // number of configurations to create
    
   // ofstream outfile("output2D.txt");   //creating file for output
    
    // parameters onto output file
  //  outfile<<"Number of Configurations: "<<n_configurations<<endl; 
   // outfile<<"Number of Atoms: "<<N<<endl; 
   // outfile<<"Monte Carlo Iterations: "<<iterations<<endl; 
   // outfile<<"Temperature: "<<T<<endl; 

  //  outfile<<"Configuration "<<"TotalEnergy "<<"Magnetisation "<<endl;   // output file header
   // for (int n=0;n<n_configurations;n++){

   //     AtomChain chain(N);    //creating an object of class AtomChain
   //     
     //   MonteCarlo (chain,N,T,iterations);     //performing monte carlo on chain
        // results are appended onto a file
     //   outfile<<n<<" "<< chain.totalEnergy() <<" "<<chain.totalMagnetisation()<<endl;    // output onto file

// }
   // outfile.close();
    return 0;
}