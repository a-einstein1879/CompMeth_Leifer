#include "cell.h"
#include <iostream>

Cell::Cell() {
    std::cout << "New cell " << this << " created" << std::endl;
    numberOfConnections = 0;
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
