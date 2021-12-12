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
    T1 matrix_a = this->matrix_;
    T3 shift = this->shift_;
    const double kError =this->error_;

    // Initialise intital vector X of size (n x 1)
    const int kDim = matrix_a.rows();
    T2 x_old = T2::Random(kDim);

    // Create identity matrix of appropriate size
    T1 identity = matrix_a;
    identity = identity.setIdentity();

    // A = A-mu * I;
    if (shift > 1e-13){
        matrix_a = matrix_a - shift * identity;
    }

    //Initialise iterative variables 
    T2 x_new;
    T3 eigenvalue=0;
    T2 error= T2::Random(kDim);
    // While loop that calculates power method until convergence,
    // Calculate lambda_new, the biggest eigenvalue of A
    while(error.norm() > kError) {
        x_new= matrix_a*x_old; 
        x_old = x_new;
        x_old /=x_new.norm();

        // Find eigenvalue with  Rayleigh quotient
        eigenvalue = x_old.transpose()*matrix_a*x_old;

        //calculate error 
        error =matrix_a * x_old - eigenvalue * x_old;
    }   

    eigenvalue -= shift;

    T2 eigenvalue_vect(1);
    eigenvalue_vect << eigenvalue;
    return eigenvalue_vect;

}   




template class Power<MatrixXd, VectorXd, double>;