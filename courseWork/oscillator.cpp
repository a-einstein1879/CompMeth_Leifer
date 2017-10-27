#include "oscillator.h"


Oscillator::Oscillator(int pphaseSpaceDimensionality) {
    variable.setPhaseSpaceDimensionality(pphaseSpaceDimensionality);
}

Variable Oscillator::solveEquation() {
    Variable var(2);
    var.setVariable(1, 13);
    return var;
}

double Oscillator::getConnectionContribution() {
    return 0;
}
