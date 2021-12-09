#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "QR.hpp"
using namespace Eigen;

// Constructor
template <typename T>
QR<T>::QR() {}

// Destructor 
template <typename T>
QR<T>::~QR() {}

// Method
// Shifted QR converges faster
//
template <typename T>
double QR<T>::SolveEquation() {
    // Get members 
    T A = this->GetMatrix();
    double error =this->GetError();
    int n = A.rows();
    // //Initialise iterative variables 
    T A_new(n,n) ;
    T Q(n,n);
    T R(n,n);
    T e =MatrixXd::Random(n, n);
    //int i=0;
    VectorXd d = A.diagonal();
    VectorXd d_new;
    while(e.norm()>error) {
    //compute QkRk= A(k-1)
    ColPivHouseholderQR<T> qr(n,n);
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
    
    //std::cout << i << std::endl;
    //i++;
    }   
    
    std::cout << d << std::endl;
    std::cout << A << std::endl;
    return 5.0;
// Should we return if it was a sucess?
}   


template class QR<MatrixXd>;