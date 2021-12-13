#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "qr.hpp"
using namespace Eigen;

// Constructor
template <typename Matrix,typename Vector,typename Scalar>
QR<Matrix,Vector,Scalar>::QR() {}

// Destructor 
template <typename Matrix,typename Vector,typename Scalar>
QR<Matrix,Vector,Scalar>::~QR() {}

// Method
// Shifted QR converges faster
//
template <typename Matrix,typename Vector,typename Scalar>
Vector QR<Matrix,Vector,Scalar>::SolveEquation() {
    //Get members 
    Matrix a = this->matrix_;
    const double kError =this->error_;

    const int kDim = a.rows();
    //Initialise iterative variables 
    Matrix a_new(kDim,kDim);
    Matrix q(kDim,kDim);
    Matrix r(kDim,kDim);

    Vector error = Vector::Random(kDim);
    Vector diag = a.diagonal();
    Vector diag_new;

    HouseholderQR<Matrix> qr(kDim,kDim);

    while(error.norm()>kError) {
    //compute QkRk= A(k-1)
    qr.compute(a);
    q=qr.householderQ();
    r=q.transpose()*a;
    //Reassemble factors Ak=RkQk
    a_new = r*q;
    a=a_new;
    diag_new = a.diagonal();
    //calculate error
    error = diag-diag_new;
    diag=diag_new;
    
    }   

    return diag;

}   


template class QR<MatrixXd, VectorXd,double>;