#ifndef POWERHEADERDEF
#define POWERHEADERDEF

#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "AbstractLinalgSolver.hpp"

template <typename T>
class Power : public AbstractLinalgSolver<T> {
public:
    // Constructor and destructor
    Power();
    virtual ~Power();

    //Methods
    virtual void SolveEquation();

};

#endif