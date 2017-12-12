#include "table.h"
#include <iostream>
#include <fstream>

Table::Table() {
    readConfig();
    createCells();
    setupAdjacency();
    timeSeries.resize(numberOfCells);
    time = 0;
}

// Form a filename and print data to file
Table::~Table() {
    for(int i = 0; i < numberOfCells; i++) {
        for(int k = 0; k < phaseSpaceDimensionality; k++) {
            std::string filename = "output";
            filename = filename + std::to_string(i);
            filename = filename + std::to_string(k);
            filename = filename + ".txt";

            std::ofstream output;
            output.open(filename);
            for(int j = 0; j < modelingTime; j++) {
                    output << timeSeries[i][j].getVariable(k) << "\n";
            }
            output.close();
        }
    }
}

bool Table::tick() {
    for(int i = 0; i < numberOfCells; i++) {
        for(int i = 0; i < 4; i++) {
            getCellById(i)->calculateRungeK(i);
        }
        Variable var(phaseSpaceDimensionality);
        var = getCellById(i)->tick();
        timeSeries[i].push_back(var);
    }
    if(time++ > modelingTime) {return 0;}
    else {return 1;}
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
    
    // reading h
    std::getline(config, line, '\t');
    std::getline(config, line, '\t');
    h = std::stod(line);
    std::getline(config, line, '\n');
    config.close();
    
    // Printing out configuration to make sure it's right
    
    std::cout << "Confiration file read"            << std::endl;
    std::cout << "Number of cells = "               << numberOfCells            << std::endl;
    std::cout << "Cell type = "                     << cellType                 << std::endl;
    std::cout << "Modeling time = "                 << modelingTime             << std::endl;
    std::cout << "Phase space dimensionality = "    << phaseSpaceDimensionality << std::endl;
    std::cout << "h = "                             << h                        << std::endl;
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
        if(!std::getline(adjacency, line, '\t')) {break;}
        source = std::stoi(line);
        std::getline(adjacency, line, '\t');
        dest = std::stoi(line);
        if(!std::getline(adjacency, line, '\n')) {break;}
        weight = std::stod(line);
        getCellById(dest)->addConnection(getCellById(source), weight);
    }
    
    adjacency.close();
}

void Table::createTimeSeries(){
    if(numberOfCells == 0 || modelingTime == 0) {return;}
    
    timeSeries.resize(numberOfCells);
    for(int i = 0; i < numberOfCells; i++) {
        timeSeries[i].reserve(modelingTime);
        for(int j = 0; j < modelingTime; j++) {
            timeSeries[i].push_back(Variable(phaseSpaceDimensionality));
        }
    }

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
        oscillators.push_back(Oscillator(phaseSpaceDimensionality, h));
    }
    oscillators[0].setVariable(1, 1);
}
