#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "power.hpp"

using namespace Eigen;

// shifted power method, where power method is when sigma=0


// Constructor
template <typename T1,typename T2,typename T3>
Power<T1, T2, T3>::Power() {}

// Destructor 
template <typename T1,typename T2,typename T3>
Power<T1, T2, T3>::~Power() {}

// Method
// power method: shifted power method is when B= A-lambda*I is input into the power method
template <typename T1,typename T2,typename T3>
T2 Power<T1, T2,T3>::SolveEquation() {

    // Get members 
    // T A = this->GetMatrix();
    T1 A = this->mMatrix;
    double shift = this->mShift;
    double error =this->mError;

    // Initialise intital vector X of size (n x 1)
    const int n = A.rows();
    T2 X = T2::Random(n,1);

    // Create identity matrix of appropriate size
    T1 I = A;
    I = I.setIdentity();

    // A = A-mu * I;
    if (shift > 1e-13){
        A = A - shift * I;
    }

    //Initialise iterative variables 
    T2 X_new;
    T3 miu=0;
    T2 e= T2::Random(n);
    // While loop that calculates power method until convergence,
    // Calculate lambda_new, the biggest eigenvalue of A
    while(e.norm() > error) {
        X_new= A*X; 
        X = X_new;
        X /=X_new.norm();

        // Find eigenvalue with  Rayleigh quotient
        miu = X.transpose()*A*X;

        //calculate error 
        e =A * X - miu * X;
    }   

    miu -= shift;

    T2 miuvect(1);
    miuvect << miu;
    return miuvect;

}   




template class Power<MatrixXd, VectorXd, double>;