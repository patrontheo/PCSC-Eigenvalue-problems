#include "AbstractLinalgSolver.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>


// Constructor
template <typename T, int dim>
AbstractLinalgSolver<T,dim>::AbstractLinalgSolver() 
    : mMatrix() {}

// Destructor 
template <typename T, int dim>
AbstractLinalgSolver<T,dim>::~AbstractLinalgSolver() {}

// Method
template <typename T, int dim>
void AbstractLinalgSolver<T,dim>::SetMatrix(T  **Matrix) { mMatrix = Matrix; }
    