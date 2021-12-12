
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
    void SetMatrix(T1 Matrix);
    void SetShift(double shift);
    void SetError(double error);
    T1 GetMatrix() const { return mMatrix; }
    double GetError() const { return mError; }
    virtual T2 SolveEquation() = 0;

protected:
    T1 mMatrix;
    double mError;
    double mShift;
};

#endif