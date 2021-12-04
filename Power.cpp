#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "Power.hpp"
using namespace Eigen;
// #include "AbstractLinalgSolver.hpp"
// shifted power method, where power method is when sigma=0


// Constructor
template <typename T>
Power<T>::Power() {}

// Destructor 
template <typename T>
Power<T>::~Power() {}

// Method
// power method: shifted power method is when B= A-lambda*I is input into the power method
template <typename T>
double Power<T>::SolveEquation() {
    // Get members 
    T A = this->GetMatrix();
    double error =this->GetError();

    // Initialise intital vector X of size (n x 1)
    int n =A.rows();
    VectorXd X =VectorXd::Random(n, 1);
    
    //Initialise iterative variables 
    double lambda_old = 0;
    VectorXd X_new;
    double lambda_new=1;
    VectorXd X_new_abs;

    // While loop that calculates power method until convergence,
    // Calculate lambda_new, the biggest eigenvalue of A
    while(abs(lambda_old-lambda_new)>error) {
    lambda_old=lambda_new;
    X_new= A*X; 
    X = X_new;
    lambda_new= X_new.maxCoeff();
    X /=lambda_new;
    }   

    return lambda_new;
}   




template class Power<MatrixXd>;