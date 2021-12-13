#ifndef QRHEADERDEF
#define QRHEADERDEF

#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "abstract_linalg_solver.hpp"

using namespace Eigen;

template <typename Matrix, typename Vector, typename Scalar>
class QR : public AbstractLinalgSolver<Matrix,Vector,Scalar> {
public:
    // Constructor and destructor
    QR();
    virtual ~QR();

    //Methods
    virtual Vector SolveEquation(); 

};

#endif