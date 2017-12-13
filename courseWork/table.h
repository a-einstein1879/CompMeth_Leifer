#ifndef TABLE_H
#define TABLE_H

#include "oscillator.h"
#include "neuron.h"
#include <vector>

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
    double h;
    void readConfig();
    void setupAdjacency();
    
    // Variable
    int phaseSpaceDimensionality;
    std::vector< std::vector<Variable> > timeSeries;
    void createTimeSeries();
    
    // Function which creates oscillators/neurons
    void createCells();
    Cell *getCellById(int id);
    
    // Oscillators
    std::vector<Oscillator> oscillators;
    void createOscillators();
    
    // Neurons
    std::vector<Neuron> neurons;
    void createNeurons();
};

#endif
