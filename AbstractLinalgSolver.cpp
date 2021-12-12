#include "AbstractLinalgSolver.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;

// Constructor
template <typename T1,typename T2,typename T3>
AbstractLinalgSolver<T1,T2,T3>::AbstractLinalgSolver() : mMatrix(), mError()  { 
}
// Destructor 
template <typename T1,typename T2,typename T3>
AbstractLinalgSolver<T1, T2,T3>::~AbstractLinalgSolver() {}

// Method
template <typename T1,typename T2,typename T3>
void AbstractLinalgSolver<T1, T2, T3>::SetMatrix(T1  Matrix) { mMatrix = Matrix; }
    
template <typename T1,typename T2,typename T3>
void AbstractLinalgSolver<T1, T2, T3>::SetError(double error) { mError = error; }

template <typename T1,typename T2,typename T3>
void AbstractLinalgSolver<T1, T2, T3>::SetShift(double shift) { mShift = shift; }

template class AbstractLinalgSolver<MatrixXd, VectorXd, double>;