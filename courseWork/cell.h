#ifndef CELL_H
#define CELL_H

#include "variable.h"
#include <vector>

class Cell {
public:
    Cell();
    Variable tick();
    void addConnection(Cell *source, double weight);
    void setPhaseSpaceDimensionality(int pphaseSpaceDimensionality);
    double getVariable(int dim);
    void setVariable(int dim, double value);
// TODO: all Runge commit needs rework and extra thinking
    void calculateRungeK(int order);
protected:
    int phaseSpaceDimensionality;
    int numberOfConnections;
    struct Connection {
        Cell *source;
        double weight;
    };
    std::vector<Connection> connections;
    
    Variable variable;
    virtual Variable solveEquation() = 0;
    virtual double f() = 0;
    virtual double g() = 0;
    double h;
    std::vector<double> rungeK;
};

#endif
