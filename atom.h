#ifndef ATOM_H
#define ATOM_H

class Atom{       // defining the atom class
    private: 
        int state;       // setting state as a private variable so that it cannot be modified outside the class
    public:
        Atom();     // default constructor

        // member function to retrieve the state of the atom. atom gets randomly assigned a value in cpp
        int getstate(); 
};

#endif