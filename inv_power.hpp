#ifndef INVPOWERHEADERDEF
#define INVPOWERHEADERDEF

#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "abstract_linalg_solver.hpp"

using namespace Eigen;

template <typename Matrix,typename Vector,typename Scalar>
class InvPower : public AbstractLinalgSolver<Matrix,Vector,Scalar> {
public:
    // Constructor and destructor
    InvPower();
    virtual ~InvPower();

    //Methods
    virtual Vector SolveEquation(); 

};

#endif