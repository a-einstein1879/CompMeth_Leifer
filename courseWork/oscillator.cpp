#include "oscillator.h"
#include <iostream>

Oscillator::Oscillator() {
}

Oscillator::Oscillator(int pphaseSpaceDimensionality, double H) {
    setPhaseSpaceDimensionality(pphaseSpaceDimensionality);
    h = H;
}

/* In this function we can see that everything is hardcoded. When I wrote this function I meant
that oscillator will always have 2 dimensions and all methods are for 2D problems */
Variable Oscillator::solveEquation() {
    Variable var(phaseSpaceDimensionality);
    double xk, yk, xkp, ykp;
    yk = variable.getVariable(0);
    xk = variable.getVariable(1);
//    std::cout << this << std::endl;
//    std::cout << "x = " << xk << "; y = " << yk << std::endl;
    
// This is Runge-Kutta method
    xkp = xk + h/6 * (getK(0) + 2 * getK(1) + 2 * getK(2) + getK(3));
    ykp = yk + h/6 * (getL(0) + 2 * getL(1) + 2 * getL(2) + getL(3));
    
// This is Euler method, we want to compare it to 4th order Runge-Kutta and Leapfrog
//    xkp = xk + h * f();
//    ykp = yk + h * g();
    
//    std::cout << "xp = " << xkp << "; yp = " << ykp << std::endl;
    var.setVariable(0, ykp);
    var.setVariable(1, xkp);
    return var;
}

double Oscillator::f() {
    return variable.getVariable(0);
}

double Oscillator::g() {
    double total = 0;
    for(int i = 0; i < numberOfConnections; i++) {
        total += connections[i].weight * connections[i].source->getVariable(1);
    }
    return total;
}

void Oscillator::calculateRungeK(int order) {
    if(order == 0) {
        rungeK[0] = f();
        rungeL[0] = g();
    }
    
    if(order == 1) {
        rungeK[1] = variable.getVariable(0) + 0.5 * h * rungeL[0];
        double total = 0;
        for(int i = 0; i < numberOfConnections; i++) {
            total += connections[i].weight * ( connections[i].source->getVariable(1) + 0.5 * h * connections[i].source->getK(0));
        }
        rungeL[1] = total;
    }
    
    if(order == 2) {
        rungeK[2] = variable.getVariable(0) + 0.5 * h * rungeL[1];
        double total = 0;
        for(int i = 0; i < numberOfConnections; i++) {
            total += connections[i].weight * ( connections[i].source->getVariable(1) + 0.5 * h * connections[i].source->getK(1));
        }
        rungeL[2] = total;
    }
    
    if(order == 3) {
        rungeK[3] = variable.getVariable(0) + h * rungeL[2];
        double total = 0;
        for(int i = 0; i < numberOfConnections; i++) {
            total += connections[i].weight * ( connections[i].source->getVariable(1) + h * connections[i].source->getK(2));
        }
        rungeL[3] = total;
    }
}
