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
template <typename Matrix,typename Vector,typename Scalar>
InvPower<Matrix, Vector,Scalar>::InvPower() {}

// Destructor 
template <typename Matrix,typename Vector,typename Scalar>
InvPower<Matrix, Vector,Scalar>::~InvPower() {}

// Method
// power method: shifted power method is when B= A-lambda*I is input into the power method
template <typename Matrix,typename Vector,typename Scalar>
Vector InvPower<Matrix,Vector,Scalar>::SolveEquation() {
    // Get members 
    Matrix matrix_a = this->matrix_;
    double kError =this->error_;
    Scalar shift = this->shift_;

    // Adding a little random number to the shift allow to be able to 
    // compute the eigenvalue even if the shift is exactly the eigenvalue
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(-1, 1);    
    shift += distr(eng) / 1e4;

    Matrix identity = matrix_a;
    identity = identity.setIdentity();

    Matrix matrix_a_shift = matrix_a;

    // A = A-mu * I;
    if (abs(shift) > 1e-13){
        matrix_a_shift = matrix_a - shift * identity;
    }

    // Initialise intital vector X of size (n x 1)
    const int kDim =matrix_a_shift.rows();
    Vector x_old =Vector::Random(kDim);
    x_old /= x_old.norm();

    //Initialise iterative variables 
    Vector x_new;
    Scalar eigenvalue = 0;
    Vector error = Vector::Random(kDim);

    double lambdaprime = 1.;

    // LU decomposition: we do it here to avoid doing it in 
    // each loop
    FullPivLU<Matrix> lu(matrix_a_shift);

    // While loop that calculates power method until convergence,
    // Calculate lambda_new, the smallest eigenvalue of A
    while(error.norm() > kError) {
        // Solving Linear system X_new= A^-1*X
        x_new = lu.solve(x_old);

        // Find eigenvalue
        lambdaprime = x_old.transpose() * x_new;
        eigenvalue = shift + 1 / lambdaprime;
        
        //We normalize the eigenvector
        x_old = x_new / x_new.norm();

        //calculate error 
        error = matrix_a * x_old - eigenvalue * x_old;
    }   

    Vector eigenvalue_vect(1);
    eigenvalue_vect<<eigenvalue;
    return eigenvalue_vect;
}    





template class InvPower<MatrixXd, VectorXd,double>;