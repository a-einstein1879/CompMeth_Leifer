#include "cell.h"
#include <iostream>

Cell::Cell() {
    std::cout << "New cell " << this << " created" << std::endl;
    numberOfConnections = 0;
}

Cell::~Cell() {
    std::cout << "Cell is deleted" << std::endl;
}

Variable Cell::tick() {
    std::cout << "Variable = (" << variable.getVariable(0) << ", " << variable.getVariable(1) << ")" << std::endl;
    variable = solveEquation();
    std::cout << "Tick" << std::endl;
    std::cout << "Variable = (" << variable.getVariable(0) << ", " << variable.getVariable(1) << ")" << std::endl;
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
