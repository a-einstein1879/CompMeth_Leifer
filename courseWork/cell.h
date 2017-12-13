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
    virtual void calculateRungeK(int order) = 0;
    /* We put getK and getL in public because there was a bug connected with the fact that getK() method is in the parent class and is inherited as protected.
     Here we work with pointer to Cell, according to structure Connection in cell.h, so possibly this can be a pointer to a class which inherits Cell as private, so it wouldn't have that method.
     We know, that this situation will never happen, so we put it in public methods. But in case you ever want to create something, which inherits cell as private think twice please. */
    double getK(int order);
    double getL(int order);
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
    std::vector<double> rungeL;
};

#endif
