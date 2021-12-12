#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "QR.hpp"
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
    T1 A = this->mMatrix;
    double error =this->mError;
    int n = A.rows();
    //Initialise iterative variables 
    T1 A_new(n,n) ;
    T1 Q(n,n);
    T1 R(n,n);
    T2 e =T2::Random(n);
    T2 d = A.diagonal();
    T2 d_new;
    
    while(e.norm()>error) {
    //compute QkRk= A(k-1)
    ColPivHouseholderQR<T1> qr(n,n);
    qr.compute(A);
    Q=qr.matrixQ();
    R=qr.matrixR(); 
    //Reassemble factors Ak=RkQk
    A_new = R*Q;
    A=A_new;
    d_new = A.diagonal();
    //calculate error
    e = d-d_new;
    d=d_new;
    
    }   
    
    return d;

}   


template class QR<MatrixXd, VectorXd,double>;