#ifndef INVPOWERHEADERDEF
#define INVPOWERHEADERDEF

#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "AbstractLinalgSolver.hpp"

using namespace Eigen;

template <typename T1,typename T2,typename T3>
class InvPower : public AbstractLinalgSolver<T1,T2,T3> {
public:
    // Constructor and destructor
    InvPower();
    virtual ~InvPower();

    //Methods
    virtual T2 SolveEquation(); 

};

#endif