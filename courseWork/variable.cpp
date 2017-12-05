#include "variable.h"

Variable::Variable() {
    phaseSpaceDimensionality = 0;
}

void Variable::setPhaseSpaceDimensionality(int phaseSpaceDimensionality){
    x.resize(phaseSpaceDimensionality);
}

Variable::Variable(int pphaseSpaceDimensionality) {
    phaseSpaceDimensionality = pphaseSpaceDimensionality;
    x.resize(phaseSpaceDimensionality);
    for(int i = 0; i < phaseSpaceDimensionality; i++)
        setVariable(i, 0);
}

double Variable::getVariable(int dim) {
    return x[dim];
}

void Variable::setVariable(int dim, double value) {
    x[dim] = value;
}
