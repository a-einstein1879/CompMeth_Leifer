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
    double h = 0.01;
    double xk, yk, xkp, ykp;
    yk = variable.getVariable(0);
    xk = variable.getVariable(1);
    double delta = getConnectionContribution();
    xkp = xk + h * yk;
    ykp = yk + h * delta;
//    std::cout << this << std::endl;
//    std::cout << "x = " << xk << "; y = " << yk << std::endl;
//    std::cout << "xp = " << xkp << "; yp = " << ykp << std::endl;
    var.setVariable(0, ykp);
    var.setVariable(1, xkp);
    return var;
//    return 0;
}

double Oscillator::getConnectionContribution() {
	double total = 0;
	for(int i = 0; i < numberOfConnections; i++) {
		total += connections[i].weight * connections[i].source->getVariable(1);
	}
    return total;
}
