#ifndef VARIABLE_H
#define VARIABLE_H

class Variable {
public:
    Variable();
    int phaseSpaceDimensionality;
    /* Following function is designed to be used in case you need an array of this objects */
    void setPhaseSpaceDimensionality(int phaseSpaceDimensionality);
    Variable(int pphaseSpaceDimensionality);
    ~Variable();
    
    /* We count dimensions from 1 here for user-friendliness */
    double getVariable(int dim);
    void setVariable(int dim, double value);
private:
    double *x;
};

#endif
