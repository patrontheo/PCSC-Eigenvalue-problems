#ifndef POWERHEADERDEF
#define POWERHEADERDEF

#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "AbstractLinalgSolver.hpp"

using namespace Eigen;

template <typename T1,typename T2,typename T3>
class Power : public AbstractLinalgSolver<T1,T2,T3> {
public:
    // Constructor and destructor
    Power();
    virtual ~Power();

    //Methods
    virtual T2 SolveEquation(); 

};

#endif