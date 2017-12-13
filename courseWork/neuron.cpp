#include "neuron.h"
#include <iostream>
#include <stdlib.h> /* rand */
#include <time.h> /* seed */

Neuron::Neuron() {
    srand(time(NULL));
}

Neuron::Neuron(int pphaseSpaceDimensionality, double H) {
    srand(time(NULL));
    setPhaseSpaceDimensionality(pphaseSpaceDimensionality);
    h = H;
    
    a = 1;
    b = 0.5;
    c = -30;
    d = 8;
    k = 0.5;
    vr = -60;
    vt = -50;
    cm = 50;
    noiseAmp = 10;
}

/* In this function we can see that everything is hardcoded. When I wrote this function I meant
 that neuron will always have 2 dimensions and all methods are for 2D problems */
Variable Neuron::solveEquation() {
    Variable var(phaseSpaceDimensionality);
    double vk, uk, vkp, ukp;
    vk = variable.getVariable(0);
    uk = variable.getVariable(1);
    //    std::cout << this << std::endl;
    //    std::cout << "x = " << xk << "; y = " << yk << std::endl;
    
    // This is Runge-Kutta method
    vkp = vk + h/6 * (getK(0) + 2 * getK(1) + 2 * getK(2) + getK(3));
    ukp = uk + h/6 * (getL(0) + 2 * getL(1) + 2 * getL(2) + getL(3));
    
    // This is Euler method, we want to compare it to 4th order Runge-Kutta and Leapfrog
    // vkp = vk + h * f();
    // ukp = uk + h * g();
    
    //    std::cout << "xp = " << xkp << "; yp = " << ykp << std::endl;
    
    // noise
    vkp = vkp - noiseAmp / 2 + rand()%noiseAmp;
    
    // Izhekevich cut off
    if(vkp >= 1) {
        vkp = c;
        ukp = uk + d;
    }
    
    var.setVariable(0, vkp);
    var.setVariable(1, ukp);
    return var;
}

double Neuron::f() {
    double u, v;
    v = variable.getVariable(0);
    u = variable.getVariable(1);
    //std::cout << (k * (v - vr) * (v - vt) - u) << std::endl;
    return k * (v - vr) * (v - vt) - u;
    //return (k*(neuronPotential[timer] - Vr)*(neuronPotential[timer] - Vt) - Um[timer] + Iex + synapticCurrent[timer])/Cm;
    /*    double total = 0;
     for(int i = 0; i < numberOfConnections; i++) {
     total += connections[i].weight * connections[i].source->getVariable(1);
     }
     return total;*/
}

double Neuron::g() {
    double u, v;
    v = variable.getVariable(0);
    u = variable.getVariable(1);
    return a * (b * (v - vr) - u);
}

void Neuron::calculateRungeK(int order) {
    if(order == 0) {
        rungeK[0] = f();
        rungeL[0] = g();
    }
    
    if(order == 1) {
        double uk, vk;
        vk = variable.getVariable(0);
        uk = variable.getVariable(1);
        
        rungeK[1] = k * (vk + 0.5 * h * rungeL[0] - vr) * (vk + 0.5 * h * rungeL[0] - vt) - uk - 0.5 * h * rungeK[0];
        rungeL[1] = a * (b * (vk + 0.5 * h * rungeL[0] - vr) - uk - 0.5 * h * rungeK[0]);
    }
    
    if(order == 2) {
        double uk, vk;
        vk = variable.getVariable(0);
        uk = variable.getVariable(1);
        
        rungeK[2] = k * (vk + 0.5 * h * rungeL[1] - vr) * (vk + 0.5 * h * rungeL[1] - vt) - uk - 0.5 * h * rungeK[1];
        rungeL[2] = a * (b * (vk + 0.5 * h * rungeL[1] - vr) - uk - 0.5 * h * rungeK[1]);
    }
    
    if(order == 3) {
        double uk, vk;
        vk = variable.getVariable(0);
        uk = variable.getVariable(1);
        
        rungeK[3] = k * (vk + h * rungeL[2] - vr) * (vk + h * rungeL[2] - vt) - uk - h * rungeK[2];
        rungeL[3] = a * (b * (vk + h * rungeL[2] - vr) - uk - h * rungeK[2]);
    }
}
