#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "InvPower.hpp"
using namespace Eigen;
// #include "AbstractLinalgSolver.hpp"
// shifted power method, where power method is when sigma=0

// Constructor
template <typename T>
InvPower<T>::InvPower() {}

// Destructor 
template <typename T>
InvPower<T>::~InvPower() {}

// Method
// power method: shifted power method is when B= A-lambda*I is input into the power method
template <typename T>
double InvPower<T>::SolveEquation() {
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
    double miu=0;
    // While loop that calculates power method until convergence,
    // Calculate lambda_new, the biggest eigenvalue of A
    while(abs(lambda_old-lambda_new)>error) {
    lambda_old=lambda_new;
    // Solving Linear system X_new= A^-1*X
    X_new = A.fullPivLu().solve(X);
    X = X_new;
    lambda_new= X_new.norm();
    X /=lambda_new;

    }   
     // Find eigenvalue with  Rayleigh quotient
    miu = X.transpose()*A*X;
    return miu;
}    





template class InvPower<MatrixXd>;