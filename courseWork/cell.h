#ifndef CELL_H
#define CELL_H

#include "variable.h"

class Cell {
public:
    Cell();
    ~Cell();
    Variable tick();
    void addConnection(Cell *source, double weight);
protected:
    int numberOfConnections;
    struct Connection {
        Cell *source;
        double weight;
    } *connections;
    void deleteConnections();
    
    Variable variable;
    virtual Variable solveEquation() = 0;
};

#endif
