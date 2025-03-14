#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "atomchain.h"
#include <time.h> 
#include <cstdlib> 

void MonteCarlo(AtomChain &chain, int N, int iterations);
int iterations;

#endif