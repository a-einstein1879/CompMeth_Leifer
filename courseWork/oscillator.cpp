#include "oscillator.h"

Oscillator::Oscillator(){
}

Oscillator::Oscillator(int pphaseSpaceDimensionality) {
    setPhaseSpaceDimensionality(pphaseSpaceDimensionality);
}

Variable Oscillator::solveEquation() {
    Variable var(phaseSpaceDimensionality);
    var.setVariable(1, 13);
    return var;
}

double Oscillator::getConnectionContribution() {
    return 0;
}
