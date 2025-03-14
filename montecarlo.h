#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "atomchain.h"
#include <time.h> 
#include <cstdlib> 

int computeEnergyChange(AtomChain &chain, int index);   // function to compute change in energy
void MonteCarlo(AtomChain &chain, int N, int iterations);  // function to perform monte carlo

#endif