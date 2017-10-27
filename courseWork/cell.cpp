#include "cell.h"
#include <iostream>

Cell::Cell() {
    std::cout << "New cell " << this << " created" << std::endl;
    numberOfConnections = 0;
}

Cell::~Cell() {
    std::cout << "Cell is deleted" << std::endl;
    deleteConnections();
}

Variable Cell::tick() {
//    variable = solveEquation();
    std::cout << "Tick" << std::endl;
    //return variable;
    return 0;
}

void Cell::setPhaseSpaceDimensionality(int pphaseSpaceDimensionality) {
    phaseSpaceDimensionality = pphaseSpaceDimensionality;
    variable.setPhaseSpaceDimensionality(phaseSpaceDimensionality);
    std::cout << "Cell " << this << " phase space dimensionality is set to " << phaseSpaceDimensionality << std::endl;
}

void Cell::addConnection(Cell *source, double weight) {
    if(numberOfConnections != 0) {
        Connection *tmpConnections = new Connection[numberOfConnections];
        for(int i = 0; i < numberOfConnections; i++) {
            tmpConnections[i].source = connections[i].source;
            tmpConnections[i].weight = connections[i].weight;
        }
        deleteConnections();
        
        connections = new Connection[++numberOfConnections];
        for(int i = 0; i < numberOfConnections; i++) {
            connections[i].source = tmpConnections[i].source;
            connections[i].weight = tmpConnections[i].weight;
        }
        delete [] tmpConnections;
        
        connections[numberOfConnections - 1].source = source;
        connections[numberOfConnections - 1].weight = weight;
    } else {
        connections = new Connection[++numberOfConnections];
        connections[0].source = source;
        connections[0].weight = weight;
    }
    std::cout << "Added new connection. Now there are " << numberOfConnections << " connections" << std::endl;
    for(int i = 0; i < numberOfConnections; i++) {
        std::cout << this << ": Source is " << connections[i].source << " weight is " << connections[i].weight << std::endl;
    }
}

void Cell::deleteConnections() {
    if(numberOfConnections == 0) {return;}
    delete [] connections;
}
