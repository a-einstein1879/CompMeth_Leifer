#include "cell.h"
#include <iostream>

Cell::Cell() {
    std::cout << "New cell " << this << " created" << std::endl;
    numberOfConnections = 0;
    rungeK.resize(4);
    rungeL.resize(4);
}

Variable Cell::tick() {
    variable = solveEquation();
    return variable;
}

void Cell::setPhaseSpaceDimensionality(int pphaseSpaceDimensionality) {
    phaseSpaceDimensionality = pphaseSpaceDimensionality;
    variable.setPhaseSpaceDimensionality(phaseSpaceDimensionality);
    std::cout << "Cell " << this << " phase space dimensionality is set to " << phaseSpaceDimensionality << std::endl;
}

void Cell::addConnection(Cell *source, double weight) {
    Connection tmp;
    tmp.source = source;
    tmp.weight = weight;
    connections.push_back(tmp);
    numberOfConnections++;
    std::cout << "Added new connection. Now there are " << connections.size() << " connections" << std::endl;
    for(int i = 0; i < numberOfConnections; i++) {
        std::cout << this << ": Source is " << connections[i].source << " weight is " << connections[i].weight << std::endl;
    }
}

double Cell::getVariable(int dim) {
    return variable.getVariable(dim);
}

void Cell::setVariable(int dim, double value) {
    variable.setVariable(dim, value);
}

void Cell::calculateRungeK(int order) {
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

double Cell::getK(int order) {
    return rungeK[order];
}

double Cell::getL(int order) {
    return rungeL[order];
}
