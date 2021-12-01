#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "Power.hpp"
#include "AbstractLinalgSolver.hpp"



// Constructor
template <typename T>
Power<T>::Power() : AbstractLinalgSolver<T> (){}

// Destructor 
template <typename T>
Power<T>::~Power() {}

// Method
template <typename T>
void Power<T>::SolveEquation() {
    T A = GetMatrix();

    std::cout << A << std::endl;
    

}