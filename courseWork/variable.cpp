#include "variable.h"

Variable::Variable() {
    phaseSpaceDimensionality = 0;
}

void Variable::setPhaseSpaceDimensionality(int phaseSpaceDimensionality){
    x = new double[phaseSpaceDimensionality];
}

Variable::Variable(int pphaseSpaceDimensionality) {
    phaseSpaceDimensionality = pphaseSpaceDimensionality;
    x = new double[phaseSpaceDimensionality];
    for(int i = 0; i < phaseSpaceDimensionality; i++)
        setVariable(i, 0);
}

Variable::~Variable() {
    if(phaseSpaceDimensionality == 0) {return;}
    delete [] x;
}

double Variable::getVariable(int dim) {
    return x[dim];
}

void Variable::setVariable(int dim, double value) {
    x[dim] = value;
}
