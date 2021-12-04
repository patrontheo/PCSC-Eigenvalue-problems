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
    pSolver = new Power<MatrixXd>;

    // Set parameters
    pSolver->SetMatrix(mat);
    pSolver->SetError(0.001);
    double eigenvalue = pSolver->SolveEquation();
    std::cout << eigenvalue << std::endl;
    delete pSolver;
    WriteCSV<double> writer;
    writer.write_data("../out_mat.csv", eigenvalue);
}