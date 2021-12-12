#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>
#include <random>

#include "inv_power.hpp"
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
    T1 A = this->mMatrix;
    double error =this->mError;
    double shift = this->mShift;

    // Adding a little random number to the shift allow to be able to 
    // compute the eigenvalue even if the shift is exactly the eigenvalue
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(-1, 1);    
    shift += distr(eng) / 1e4;

    T1 I = A;
    I = I.setIdentity();

    T1 A_shift = A;

    // A = A-mu * I;
    if (abs(shift) > 1e-13){
        A_shift = A - shift * I;
    }

    // Initialise intital vector X of size (n x 1)
    int n =A_shift.rows();
    T2 X =T2::Random(n);
    X /= X.norm();

    //Initialise iterative variables 
    T2 X_new;
    T3 miu = 0;
    T2 e = T2::Random(n);

    double lambdaprime = 1.;

    // LU decomposition: we do it here to avoid doing it in 
    // each loop
    FullPivLU<T1> lu(A_shift);

    // While loop that calculates power method until convergence,
    // Calculate lambda_new, the smallest eigenvalue of A
    while(e.norm() > error) {
        // Solving Linear system X_new= A^-1*X
        X_new = lu.solve(X);

        // Find eigenvalue
        lambdaprime = X.transpose() * X_new;
        miu = shift + 1 / lambdaprime;
        
        //We normalize the eigenvector
        X = X_new / X_new.norm();

        //calculate error 
        e = A * X - miu * X;
    }   

    T2 miuvect(1);
    miuvect<<miu;
    return miuvect;
}    





template class InvPower<MatrixXd, VectorXd,double>;