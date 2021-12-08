#include "AbstractLinalgSolver.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;

// Constructor
template <typename T>
AbstractLinalgSolver<T>::AbstractLinalgSolver() : mMatrix(), mError()  { 
}
// Destructor 
template <typename T>
AbstractLinalgSolver<T>::~AbstractLinalgSolver() {}

// Method
template <typename T>
void AbstractLinalgSolver<T>::SetMatrix(T  Matrix) { mMatrix = Matrix; }
    
template <typename T>
void AbstractLinalgSolver<T>::SetError(double error) { mError = error; }

template <typename T>
void AbstractLinalgSolver<T>::SetShift(double shift) { mShift = shift; }

template class AbstractLinalgSolver<MatrixXd>;