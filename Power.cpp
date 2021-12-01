#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "Power.hpp"
// #include "AbstractLinalgSolver.hpp"



// Constructor
template <typename T>
Power<T>::Power() {}
//Power<T>::Power() : AbstractLinalgSolver<T>::AbstractLinalgSolver (){} pas besoin je crois

// Destructor 
template <typename T>
Power<T>::~Power() {}

// Method
template <typename T>
void Power<T>::SolveEquation() {
    T A = this->GetMatrix();
    std::cout << A << std::endl;
}


template class Power<Eigen::MatrixXd>;