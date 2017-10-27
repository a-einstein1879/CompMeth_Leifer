#include "table.h"
#include <iostream>
#include <fstream>

Table::Table() {
    readConfig();
    setupAdjacency();
    createTimeSeries();
    Cell cell1, cell2;
    cell1.addConnection(&cell2, 2);
    cell2.addConnection(&cell1, -2);
}

Table::~Table() {
    deleteTimeSeries();
}

void Table::tick() {
}

void Table::readConfig() {
    std::string line;
    std::ifstream config;
    config.open ("config.txt", std::ifstream::in);
    
    // reading number of cells
    std::getline(config, line, '\t');
    std::getline(config, line, '\t');
    numberOfCells = std::stoi(line);
    std::getline(config, line, '\n');
    
    // reading cell type
    std::getline(config, line, '\t');
    std::getline(config, line, '\t');
    cellType = std::stoi(line);
    std::getline(config, line, '\n');
    
    // reading modeling time
    std::getline(config, line, '\t');
    std::getline(config, line, '\t');
    modelingTime = std::stoi(line);
    std::getline(config, line, '\n');
    
    // reading phase space dimensionality
    std::getline(config, line, '\t');
    std::getline(config, line, '\t');
    phaseSpaceDimensionality = std::stoi(line);
    std::getline(config, line, '\n');
    config.close();
    
    // Printing out configuration to make sure it's right
    
    std::cout << "Confiration file read"            << std::endl;
    std::cout << "Number of cells = "               << numberOfCells            << std::endl;
    std::cout << "Cell type = "                     << cellType                 << std::endl;
    std::cout << "Modeling time = "                 << modelingTime             << std::endl;
    std::cout << "Phase space dimensionality = "    << phaseSpaceDimensionality << std::endl;
}

void Table::setupAdjacency() {
    std::cout << "Adjacency file read" << std::endl;
    
    std::string line;
    std::ifstream adjacency;
    adjacency.open("adjacency.txt", std::ifstream::in);
    // Skipping header
    std::getline(adjacency, line, '\n');
    
    while(std::getline(adjacency, line, '\n')) {
        std::cout << line << std::endl;
    }
    
    adjacency.close();
}

void Table::createTimeSeries(){
    if(numberOfCells == 0 || modelingTime == 0) {return;}
    
    timeSeries = new Variable*[numberOfCells];
    for(int i = 0; i < numberOfCells; i++) {
        timeSeries[i] = new Variable[modelingTime];
    }
    for(int i = 0; i < numberOfCells; i++)
        for(int j = 0; j < modelingTime; j++)
            timeSeries[i][j].setPhaseSpaceDimensionality(phaseSpaceDimensionality);
    
    std::cout << "Time series of size " << numberOfCells << " x " << modelingTime << " in Table created" << std::endl;
}

void Table::deleteTimeSeries(){
    if(numberOfCells == 0 || modelingTime == 0) {return;}
    
    delete [] timeSeries;
    
    std::cout << "Time series in Table deleted" << std::endl;
}

void Table::createOscillators() {
}

void Table::deleteOscillators() {
}
