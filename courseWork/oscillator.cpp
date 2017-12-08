#include "oscillator.h"
#include <iostream>

Oscillator::Oscillator() {
}

Oscillator::Oscillator(int pphaseSpaceDimensionality) {
    setPhaseSpaceDimensionality(pphaseSpaceDimensionality);
}

Variable Oscillator::solveEquation() {
    Variable var(phaseSpaceDimensionality);
    double h = 0.01;
    double xk, yk, xkp, ykp;
    yk = variable.getVariable(0);
    xk = variable.getVariable(1);
    std::cout << this << std::endl;
    std::cout << "x = " << xk << "; y = " << yk << std::endl;
    double delta = getConnectionContribution();
    xkp = xk + h * yk;
    ykp = yk + h * delta;
//    std::cout << "xp = " << xkp << "; yp = " << ykp << std::endl;
    var.setVariable(0, ykp);
    var.setVariable(1, xkp);
    return var;
}

double Oscillator::getConnectionContribution() {
    double total = 0;
    for(int i = 0; i < numberOfConnections; i++) {
        std::cout << "Weight = " << connections[i].weight << "; x = " << connections[i].source->getVariable(1) << std::endl;
        total += connections[i].weight * connections[i].source->getVariable(1);
    }
    return total;
}
