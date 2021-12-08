#ifndef INVPOWERHEADERDEF
#define INVPOWERHEADERDEF

#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "AbstractLinalgSolver.hpp"

using namespace Eigen;

template <typename T>
class InvPower : public AbstractLinalgSolver<T> {
public:
    // Constructor and destructor
    InvPower();
    virtual ~InvPower();

    //Methods
    virtual double SolveEquation(); 

};

#endif