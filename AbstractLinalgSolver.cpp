#include "AbstractLinalgSolver.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>


// Constructor
template <typename T>
AbstractLinalgSolver<T>::AbstractLinalgSolver() { 
    T mMatrix(3,3);
    mMatrix << 1, 2, 3, 4, 5, 6,7, 8, 9;
}
// Destructor 
template <typename T>
AbstractLinalgSolver<T>::~AbstractLinalgSolver() {}

// Method
template <typename T>
void AbstractLinalgSolver<T>::SetMatrix(T  Matrix) { mMatrix = Matrix; }
    