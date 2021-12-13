
#ifndef ABSTRACTLINALGSOLVERHEADERDEF
#define ABSTRACTLINALGSOLVERHEADERDEF


#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

using namespace Eigen;

template <typename Matrix, typename Vector,typename Scalar> 
class AbstractLinalgSolver{
public:

    // Constructor and destructor
    AbstractLinalgSolver();
    virtual ~AbstractLinalgSolver();

    // Methods
    void SetMatrix(Matrix matrix);
    void SetShift(Scalar shift);
    void SetError(double error);
    Matrix GetMatrix() const { return matrix_; }
    double GetError() const { return error_; }
    virtual Vector SolveEquation() = 0;

protected:
    Matrix matrix_;
    double error_;
    Scalar shift_;
};

#endif