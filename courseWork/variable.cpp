#include "variable.h"

Variable::Variable() {
}

void Variable::setPhaseSpaceDimensionality(int phaseSpaceDimensionality){
    x = new double[phaseSpaceDimensionality];
}

Variable::Variable(int phaseSpaceDimensionality) {
    x = new double[phaseSpaceDimensionality];
}

Variable::~Variable() {
    delete[] x;
}

double Variable::getVariable(int dim) {
    return x[dim - 1];
}

void Variable::setVariable(int dim, double value) {
    x[dim - 1] = value;
}
