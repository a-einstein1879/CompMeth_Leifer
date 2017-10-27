#ifndef CELL_H
#define CELL_H

#include "variable.h"

class Cell {
public:
    Cell();
    ~Cell();
    Variable tick();
    void addConnection(Cell *source, double weight);
    void setPhaseSpaceDimensionality(int pphaseSpaceDimensionality);
protected:
    int phaseSpaceDimensionality;
    int numberOfConnections;
    struct Connection {
        Cell *source;
        double weight;
    } *connections;
    void deleteConnections();
    
    Variable variable;
    virtual Variable solveEquation() {}
};

#endif
