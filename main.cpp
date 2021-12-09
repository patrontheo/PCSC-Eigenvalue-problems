#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>

#include "AbstractLinalgSolver.hpp"
#include "Power.hpp"
#include "Input.hpp"
#include "LoadCSV.hpp"
#include "Output.hpp"
#include "WriteCSV.hpp"
#include "InvPower.hpp"
#include "QR.hpp"

using namespace Eigen;

int main(int argc, char *argv[])
{
    MatrixXd mat;
    LoadCSV<MatrixXd> loader;
    mat = loader.load_data("../mat.csv");
    
    std::cout << mat << std::endl;
    // mat(1,1) = 350;    

    // Solving
    AbstractLinalgSolver<MatrixXd> *pSolver = 0;
    pSolver = new QR<MatrixXd>;

    // Set parameters
    pSolver->SetMatrix(mat);
    pSolver->SetError(0.01);
    //double eigenvalue = pSolver->SolveEquation();
    double d =pSolver->SolveEquation();
    //std::cout << d << std::endl;
    delete pSolver;
    //WriteCSV<double> writer;
    //writer.write_data("../out_mat.csv", eigenvalue);
}