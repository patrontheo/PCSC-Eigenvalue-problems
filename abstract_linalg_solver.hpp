
#ifndef ABSTRACTLINALGSOLVERHEADERDEF
#define ABSTRACTLINALGSOLVERHEADERDEF


#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

using namespace Eigen;

template <typename T1, typename T2,typename T3> 
class AbstractLinalgSolver{
public:

    // Constructor and destructor
    AbstractLinalgSolver();
    virtual ~AbstractLinalgSolver();

    // Methods
    void SetMatrix(T1 matrix);
    void SetShift(T3 shift);
    void SetError(double error);
    T1 GetMatrix() const { return matrix_; }
    double GetError() const { return error_; }
    virtual T2 SolveEquation() = 0;

protected:
    T1 matrix_;
    double error_;
    T3 shift_;
};

#endif