#include "table.h"
#include <iostream>
#include <fstream>

Table::Table() {
    readConfig();
    createCells();
    setupAdjacency();
    createTimeSeries();
    time = 0;
}

Table::~Table() {
}

bool Table::tick() {
    Variable var(2);
    var = getCellById(0)->tick();
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
    
    int source, dest;
    double weight;
    while(1) {
        std::getline(adjacency, line, '\t');
        source = std::stoi(line);
        std::getline(adjacency, line, '\t');
        dest = std::stoi(line);
        if(!std::getline(adjacency, line, '\n')) {break;}
        weight = std::stoi(line);
        getCellById(dest)->addConnection(getCellById(source), weight);
    }
    
    adjacency.close();
}

void Table::createTimeSeries(){
    if(numberOfCells == 0 || modelingTime == 0) {return;}
    
//                for(int i = 0; i < numberOfNodes; i++)
//                        vectors[i].resize(numberOfColors * numberOfWeights);

    timeSeries.resize(numberOfCells);
    for(int i = 0; i < numberOfCells; i++) {
        timeSeries[i].reserve(modelingTime);
	for(int j = 0; j < modelingTime; j++) {
            timeSeries[i].push_back(Variable(phaseSpaceDimensionality));
        }
    }

  /*  timeSeries = new Variable*[numberOfCells];
    for(int i = 0; i < numberOfCells; i++) {
        timeSeries[i] = new Variable[modelingTime];
    }
    for(int i = 0; i < numberOfCells; i++)
        for(int j = 0; j < modelingTime; j++)
            timeSeries[i][j].setPhaseSpaceDimensionality(phaseSpaceDimensionality);
    */
    std::cout << "Time series of size " << numberOfCells << " x " << modelingTime << " in Table created" << std::endl;
}

void Table::createCells() {
    if(cellType == 1) {
        createOscillators();
    }
}

Cell* Table::getCellById(int id) {
    if(cellType == 1) {
        return &oscillators[id];
    }
    std::cout << "Wrong scenario" << std::endl;
    return 0;
}

void Table::createOscillators() {
    std::cout << "Creating " << numberOfCells << " oscillators" << std::endl;
    oscillators.reserve(numberOfCells);
    for(int i = 0; i < numberOfCells; i++) {
        oscillators.push_back(Oscillator(phaseSpaceDimensionality));
    }
}
