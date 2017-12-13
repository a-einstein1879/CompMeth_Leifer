#ifndef NEURON_H
#define NEURON_H

#include "cell.h"

class Neuron : public Cell {
public:
    Neuron();
    Neuron(int pphaseSpaceDimensionality, double H);
private:
    double f();
    double g();
    Variable solveEquation();
    void calculateRungeK(int order);
};

#endif
