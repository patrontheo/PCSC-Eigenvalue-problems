#ifndef POWERHEADERDEF
#define POWERHEADERDEF

#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "abstract_linalg_solver.hpp"

using namespace Eigen;

template <typename Matrix,typename Vector,typename Scalar>
class Power : public AbstractLinalgSolver<Matrix,Vector,Scalar> {
public:
    // Constructor and destructor
    Power();
    virtual ~Power();

    //Methods
    virtual Vector SolveEquation(); 

};

#endif