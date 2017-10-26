#include "table.h"
#include <iostream>
#include <fstream>

Table::Table() {
    readConfig();
}

Table::~Table() {
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
    
    // reading modeling time
    std::getline(config, line, '\t');
    std::getline(config, line, '\t');
    phaseSpaceDimensionality = std::stoi(line);
    std::getline(config, line, '\n');
    config.close();
    
    // Printing out configuration to make sure it's right
    std::cout << "Number of cells = "               << numberOfCells            << std::endl;
    std::cout << "Cell type = "                     << cellType                 << std::endl;
    std::cout << "Modeling time = "                 << modelingTime             << std::endl;
    std::cout << "Phase space dimensionality = "    << phaseSpaceDimensionality << std::endl;
}

void Table::setupAdjacency() {
}

void Table::createOscillators() {
}

void Table::deleteOscillators() {
}
