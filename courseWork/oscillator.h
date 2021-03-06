#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include "cell.h"

class Oscillator : public Cell {
public:
    Oscillator();
    Oscillator(int pphaseSpaceDimensionality, double H);
private:
    double f();
    double g();
    Variable solveEquation();
    void calculateRungeK(int order);
};

#endif
