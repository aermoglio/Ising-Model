#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "atomgrid.h"
#include "atom.h"
#include <time.h> 
#include <cstdlib> 

int computeEnergyChange(AtomGrid &grid, int N, int row, int col);   // function to compute change in energy
void MonteCarlo(AtomGrid &grid, int N, double T, int iterations);  // function to perform monte carlo

#endif