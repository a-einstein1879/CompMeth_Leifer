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
    int phaseSpaceDimensionality;
    Variable **variable;
    
    // Oscillators
//    Oscillator *oscillators;
    void createOscillators();
    void deleteOscillators();
    
    // Neurons
};

#endif
