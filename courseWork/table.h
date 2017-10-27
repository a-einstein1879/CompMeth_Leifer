#ifndef TABLE_H
#define TABLE_H

#include "oscillator.h"
#include "neuron.h"

class Table {
public:
    Table();
    ~Table();
    bool tick();
private:
    int cellType;
    int numberOfCells;
    int time;
    int modelingTime;
    void readConfig();
    void setupAdjacency();
    
    // Variable
    int phaseSpaceDimensionality;
    Variable **timeSeries; // Size numberOfCells x modelingTime
    void createTimeSeries();
    void deleteTimeSeries();
    
    // Function which creates oscillators/neurons
    void createCells();
    void deleteCells();
    Cell *getCellById(int id);
    
    // Oscillators
    Oscillator *oscillators;
    void createOscillators();
    void deleteOscillators();
    
    // Neurons
};

#endif
