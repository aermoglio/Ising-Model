This project consists of a Monte Carlo simulation of the Ising model, used to create different spin configurations and use those to determine the macroscopic properties of a system.

The project is divided into the following Branches:

main 
|
|_ _ 1DAnalysis
|
|_ _ 2D
     |
     |_ 2DAnalysis

To switch branches, use the "git checkout (nameofbranch)" command on the terminal. 

For all branches, the code is executed through:
$ make
$ ./program

The outputs of all branches are in the form of txt files, which were then visualised using python. 

NOTE: Due to the nature of the clone feature, branches are stored in the origin remote by default. Use the branch checkout feature to make a copy locally.

The contents of each branch are the following:

main:
- Contains the 1D ising model simulation, with objects Atom, AtomChain, and a MonteCarlo function. 
- Executing the code produces an output1D.txt file containing the index of the FINAL configuration produced by the monte carlo and corresponding energy and magnetisation of that configuration. 
- All configurations are for a given temperature, and the number of configurations and other parameters can be modified in the main.cpp file. 
- The python code plots histograms of the energy and magnetisation at a given temperature, and this is done by writing 
    $ python output.py 
in the terminal.

1DAnalysis:
- Slightly modifies the main.cpp code from the main branch to loop over a range of temperatures and obtain the average energy and magnetisation of a given number of configuratuons (for each temperature)
- The outputs of the code are written in the energy_vs_temperature1D.txt and in the magnetisation_vs_temperature1D.txt files
- The outputs are visualised in the form of scatter plots, either as a plot of average energy against temperature, or absolute average magnetisation against temperature
- To produce plots, write the following in the terminal:

        $ python plots.py 

2D:
- Keeps the same base code as the main branch but modifies it so as to create an AtomGrid instead of an AtomChain, producing a grid of atoms with dimensions NxN.
- Executing code produces an output2D.txt file containing the index of the FINAL configuration produced by the monte carlo and corresponding energy and magnetisation of that configuration. 
- All configurations are for a given temperature, and the number of configurations and other parameters can be modified in the main.cpp file. 
- The python code plots histograms of the energy and magnetisation at a given temperature, and this is done by writing 
    $ python output.py 
    in the terminal.

2DAnalysis:
- Branch from the 2D branch. Like in 1DAnalysis, the code loops over a range of temperatures and obtains the average energy and magnetisation for all the final configurations of a given temperature produced. 
- The outputs of the code are written in the energy_vs_temperature2D.txt and in the magnetisation_vs_temperature2D.txt files
- The outputs are visualised in the form of scatter plots, either as a plot of average energy against temperature, or absolute average magnetisation against temperature
- To produce plots, write the following in the terminal:

        $ python plots.py 


