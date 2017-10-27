#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include "cell.h"

class Oscillator : public Cell {
public:
    Oscillator(int pphaseSpaceDimensionality = 2);
private:
    Variable solveEquation();
    double getConnectionContribution();
};

#endif
