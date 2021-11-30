#ifndef POWERHEADERDEF
#define POWERHEADERDEF


#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "AbstractLinalgSolver.hpp"

template <typename T, int dim>
class Power : public AbstractLinalgSolver<T, dim> {
public:
    // Constructor and destructor
    Power();
    virtual ~Power();

    //Methods
    T GetMatrix() const { return mMatrix; };
    virtual void SolveEquation();

private:
    T mMatrix[dim][dim];

};

#endif