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
    T1 a = this->mMatrix;
    double error =this->mError;

    int dim = A.rows();
    //Initialise iterative variables 
    T1 a_new(dim,dim);
    T1 Q(dim,dim);
    T1 R(dim,dim);

    T2 e = T2::Random(n);
    T2 diag = A.diagonal();
    T2 diag_new;

    HouseholderQR<T1> qr(n,n);

    while(e.norm()>error) {
    //compute QkRk= A(k-1)
    qr.compute(a);
    q=qr.householderQ();
    r=Q.transpose()*a;
    //Reassemble factors Ak=RkQk
    a_new = r*q;
    a=a_new;
    diag_new = a.diagonal();
    //calculate error
    e = diag-diag_new;
    diag=diag_new;
    
    }   

    return diag;

}   


template class QR<MatrixXd, VectorXd,double>;