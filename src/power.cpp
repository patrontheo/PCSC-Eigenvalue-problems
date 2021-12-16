#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "power.hpp"

using namespace Eigen;


// Constructor
template <typename Matrix,typename Vector,typename Scalar>
Power<Matrix, Vector, Scalar>::Power() {}

// Destructor 
template <typename Matrix,typename Vector,typename Scalar>
Power<Matrix, Vector, Scalar>::~Power() {}

// Method
// Power method
template <typename Matrix,typename Vector,typename Scalar>
Vector Power<Matrix, Vector,Scalar>::SolveEquation() {
    // Get members 
    Matrix matrix_a = this->GetMatrix();
    const double kError =this->GetError();

    // Initialise initial vector X of size (n x 1)
    const int kDim = matrix_a.rows();
    Vector x_old = Vector::Random(kDim);
    x_old /= x_old.norm();

    //Initialise iterative variables 
    Vector x_new;
    Scalar eigenvalue=0;
    Vector error= Vector::Random(kDim);
    // While loop that calculates power method until convergence,
    // Calculate lambda_new, the biggest eigenvalue of A
    while(error.norm() > kError) {
        x_new = matrix_a * x_old; 
        x_old = x_new / x_new.norm();

        // Find eigenvalue with  Rayleigh quotient
        eigenvalue = x_old.transpose() * matrix_a * x_old;

        //calculate error 
        error = matrix_a * x_old - eigenvalue * x_old;
    }   

    Vector eigenvalue_vect(1);
    eigenvalue_vect << eigenvalue;
    return eigenvalue_vect;

}   




template class Power<MatrixXd, VectorXd, double>;