#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "InvPower.hpp"
using namespace Eigen;

// shifted power method, where power method is when sigma=0

// Constructor
template <typename T1,typename T2,typename T3>
InvPower<T1, T2,T3>::InvPower() {}

// Destructor 
template <typename T1,typename T2,typename T3>
InvPower<T1, T2,T3>::~InvPower() {}

// Method
// power method: shifted power method is when B= A-lambda*I is input into the power method
template <typename T1,typename T2,typename T3>
T2 InvPower<T1,T2,T3>::SolveEquation() {
    // Get members 
    T1 A = this->GetMatrix();
    double error =this->GetError();

    // Initialise intital vector X of size (n x 1)
    int n =A.rows();
    T2 X =T2::Random(n);
    
    //Initialise iterative variables 
    T2 X_new;
    T3 miu=0;
    T2 e= T2::Random(n);
    // While loop that calculates power method until convergence,
    // Calculate lambda_new, the biggest eigenvalue of A
    while(e.norm() >error) {
    // Solving Linear system X_new= A^-1*X
    X_new = A.fullPivLu().solve(X);
    X = X_new;
    X /=X_new.norm();

     // Find eigenvalue with  Rayleigh quotient
    miu = X.transpose()*A*X;

    //calculate error 
    e =A*X-miu*X;
    }   
    T2 miuvect(1);
    miuvect<<miu;
    return miuvect;
}    





template class InvPower<MatrixXd, VectorXd,double>;