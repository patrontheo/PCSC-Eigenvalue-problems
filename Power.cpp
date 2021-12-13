#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "power.hpp"

using namespace Eigen;

// shifted power method, where power method is when sigma=0


// Constructor
template <typename Matrix,typename Vector,typename Scalar>
Power<Matrix, Vector, Scalar>::Power() {}

// Destructor 
template <typename Matrix,typename Vector,typename Scalar>
Power<Matrix, Vector, Scalar>::~Power() {}

// Method
// power method: shifted power method is when B= A-lambda*I is input into the power method
template <typename Matrix,typename Vector,typename Scalar>
Vector Power<Matrix, Vector,Scalar>::SolveEquation() {
    // Get members 
    Matrix matrix_a = this->matrix_;
    Scalar shift = this->shift_;
    const double kError =this->error_;

    // Initialise intital vector X of size (n x 1)
    const int kDim = matrix_a.rows();
    Vector x_old = Vector::Random(kDim);

    // Create identity matrix of appropriate size
    Matrix identity = matrix_a;
    identity = identity.setIdentity();

    // A = A-mu * I;
    if (shift > 1e-13){
        matrix_a = matrix_a - shift * identity;
    }

    //Initialise iterative variables 
    Vector x_new;
    Scalar eigenvalue=0;
    Vector error= Vector::Random(kDim);
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

    Vector eigenvalue_vect(1);
    eigenvalue_vect << eigenvalue;
    return eigenvalue_vect;

}   




template class Power<MatrixXd, VectorXd, double>;