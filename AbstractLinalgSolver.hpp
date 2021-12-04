
#ifndef ABSTRACTLINALGSOLVERHEADERDEF
#define ABSTRACTLINALGSOLVERHEADERDEF


#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

using namespace Eigen;

template <typename T> 
class AbstractLinalgSolver{
public:

    // Constructor and destructor
    AbstractLinalgSolver();
    virtual ~AbstractLinalgSolver();

    // Methods
    void SetMatrix(T Matrix);
    void SetError(double error);
    T GetMatrix() const { return mMatrix; }
    double GetError() const { return mError; }
    virtual double SolveEquation() = 0;

protected:
    T mMatrix;
    double mError;
};

#endif