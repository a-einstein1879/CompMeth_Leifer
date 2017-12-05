#ifndef VARIABLE_H
#define VARIABLE_H

#include <vector>

class Variable {
public:
    Variable();
    int phaseSpaceDimensionality;
    /* Following function is designed to be used in case you need an array of this objects */
    void setPhaseSpaceDimensionality(int phaseSpaceDimensionality);
    Variable(int pphaseSpaceDimensionality);
    
    double getVariable(int dim);
    void setVariable(int dim, double value);
private:
    std::vector<double> x;
};

#endif
