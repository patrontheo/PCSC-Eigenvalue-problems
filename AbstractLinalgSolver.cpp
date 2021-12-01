#include "AbstractLinalgSolver.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>


// Constructor
template <typename T>
AbstractLinalgSolver<T>::AbstractLinalgSolver() : mMatrix() { 
}
// Destructor 
template <typename T>
AbstractLinalgSolver<T>::~AbstractLinalgSolver() {}

// Method
template <typename T>
void AbstractLinalgSolver<T>::SetMatrix(T  Matrix) { mMatrix = Matrix; }
    

template class AbstractLinalgSolver<Eigen::MatrixXd>;