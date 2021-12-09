#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "Power.hpp"
using namespace Eigen;

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
    VectorXd X_new;
    double miu=0;
    VectorXd e= VectorXd::Random(n, 1);
    // While loop that calculates power method until convergence,
    // Calculate lambda_new, the biggest eigenvalue of A
    while(e.norm() >error) {
    X_new= A*X; 
    X = X_new;
    X /=X_new.norm();

     // Find eigenvalue with  Rayleigh quotient
    miu = X.transpose()*A*X;

    //calculate error 
    e =A*X-miu*X;
    }   
    
    
    return miu;
}   




template class Power<MatrixXd>;