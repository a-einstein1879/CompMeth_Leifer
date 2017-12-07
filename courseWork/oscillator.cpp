#include "oscillator.h"

Oscillator::Oscillator() {
}

Oscillator::Oscillator(int pphaseSpaceDimensionality) {
    setPhaseSpaceDimensionality(pphaseSpaceDimensionality);
    variable.setVariable(0, 1);
}
#include <iostream> 
Variable Oscillator::solveEquation() {
    Variable var(phaseSpaceDimensionality);
    double h = 0.1;
    double xk, yk, xkp, ykp;
    yk = variable.getVariable(0);
    xk = variable.getVariable(1);
    xkp = xk + h * yk;
    ykp = yk + h * (-xk);
//    std::cout << "x = " << xk << "; y = " << yk << std::endl;
//    std::cout << "xp = " << xkp << "; yp = " << ykp << std::endl;
    var.setVariable(0, xkp);
    var.setVariable(1, ykp);
    return var;
}

double Oscillator::getConnectionContribution() {
    return 0;
}
