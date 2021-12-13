#include "abstract_linalg_solver.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;

// Constructor
template <typename Matrix,typename Vector,typename Scalar>
AbstractLinalgSolver<Matrix,Vector,Scalar>::AbstractLinalgSolver() : matrix_(), error_(),  shift_() { 
}
// Destructor 
template <typename Matrix,typename Vector,typename Scalar>
AbstractLinalgSolver<Matrix, Vector,Scalar>::~AbstractLinalgSolver() {}

// Method
template <typename Matrix,typename Vector,typename Scalar>
void AbstractLinalgSolver<Matrix, Vector, Scalar>::SetMatrix(Matrix  matrix) { matrix_ = matrix; }
    
template <typename Matrix,typename Vector,typename Scalar>
void AbstractLinalgSolver<Matrix, Vector, Scalar>::SetError(double error) { error_ = error; }

template <typename Matrix,typename Vector,typename Scalar>
void AbstractLinalgSolver<Matrix, Vector, Scalar>::SetShift(Scalar shift) { shift_ = shift; }

template class AbstractLinalgSolver<MatrixXd, VectorXd, double>;