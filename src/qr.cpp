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
// QR method
template <typename Matrix,typename Vector,typename Scalar>
Vector QR<Matrix,Vector,Scalar>::SolveEquation() {
    //Get members 
    Matrix a = this->GetMatrix();
    const double kError =this->GetError();

    const int kDim = a.rows();
    //Initialise iterative variables 
    Matrix a_new(kDim,kDim);
    Matrix q(kDim,kDim);
    Matrix r(kDim,kDim);

    Vector error = Vector::Random(kDim);
    Vector diag = a.diagonal();
    Vector diag_new;

    //QR decomposition
    HouseholderQR<Matrix> qr(kDim,kDim);

    while(error.norm() > kError) {
        //compute Q_k*R_k= A_(k-1)
        qr.compute(a);
        q = qr.householderQ();
        r = q.transpose()*a;

        //Reassemble factors A_k=R_k*Q_k
        a_new = r * q;
        a = a_new;
        diag_new = a.diagonal();

        //calculate error
        error = diag - diag_new;
        diag = diag_new;
    }   

    return diag;
}   


template class QR<MatrixXd, VectorXd,double>;