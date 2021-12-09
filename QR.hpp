#ifndef QRHEADERDEF
#define QRHEADERDEF

#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

#include "AbstractLinalgSolver.hpp"

using namespace Eigen;

template <typename T>
class QR : public AbstractLinalgSolver<T> {
public:
    // Constructor and destructor
    QR();
    virtual ~QR();

    //Methods
    virtual double SolveEquation(); 

};

#endif