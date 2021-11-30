#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "Power.hpp"
#include "AbstractLinalgSolver.hpp"



// Constructor
template <typename T, int dim>
Power<T,dim>::Power() {}

// Destructor 
template <typename T, int dim>
Power<T,dim>::~Power() {}

// Method
template <typename T, int dim>
void Power<T,dim>::SolveEquation() {
    T A[dim][dim] = GetMatrix();

    //Print to check it works 
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
        std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
    

}