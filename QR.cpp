#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "qr.hpp"
using namespace Eigen;

// Constructor
template <typename T1,typename T2,typename T3>
QR<T1,T2,T3>::QR() {}

// Destructor 
template <typename T1,typename T2,typename T3>
QR<T1,T2,T3>::~QR() {}

// Method
// Shifted QR converges faster
//
template <typename T1,typename T2,typename T3>
T2 QR<T1,T2,T3>::SolveEquation() {
    //Get members 
    T1 a = this->matrix_;
    const double kError =this->error_;

    const int kDim = a.rows();
    //Initialise iterative variables 
    T1 a_new(kDim,kDim);
    T1 q(kDim,kDim);
    T1 r(kDim,kDim);

    T2 error = T2::Random(kDim);
    T2 diag = a.diagonal();
    T2 diag_new;

    HouseholderQR<T1> qr(kDim,kDim);

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