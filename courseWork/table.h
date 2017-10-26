#ifndef TABLE_H
#define TABLE_H

#include "cell.h"

class Table {
public:
    Table();
    ~Table();
    void tick();
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
    
    
    // Oscillators
//    Oscillator *oscillators;
    void createOscillators();
    void deleteOscillators();
    
    // Neurons
};

#endif
