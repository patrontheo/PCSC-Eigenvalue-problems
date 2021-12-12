#include "abstract_linalg_solver.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;

// Constructor
template <typename T1,typename T2,typename T3>
AbstractLinalgSolver<T1,T2,T3>::AbstractLinalgSolver() : matrix_(), error_(),  shift_() { 
}
// Destructor 
template <typename T1,typename T2,typename T3>
AbstractLinalgSolver<T1, T2,T3>::~AbstractLinalgSolver() {}

// Method
template <typename T1,typename T2,typename T3>
void AbstractLinalgSolver<T1, T2, T3>::SetMatrix(T1  matrix) { matrix_ = matrix; }
    
template <typename T1,typename T2,typename T3>
void AbstractLinalgSolver<T1, T2, T3>::SetError(double error) { error_ = error; }

template <typename T1,typename T2,typename T3>
void AbstractLinalgSolver<T1, T2, T3>::SetShift(T3 shift) { shift_ = shift; }

template class AbstractLinalgSolver<MatrixXd, VectorXd, double>;