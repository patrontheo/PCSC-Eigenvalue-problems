
#ifndef ABSTRACTLINALGSOLVERHEADERDEF
#define ABSTRACTLINALGSOLVERHEADERDEF


#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>


template <typename T> 
class AbstractLinalgSolver{
public:

    // Constructor and destructor
    AbstractLinalgSolver();
    virtual ~AbstractLinalgSolver();

    // Methods
    void SetMatrix(T Matrix);
    T GetMatrix() const { return mMatrix; }
    virtual void SolveEquation() = 0;

protected:
    T mMatrix;
};

#endif