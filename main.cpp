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


using Eigen::MatrixXd;
using Eigen::Matrix3d;



int main(int argc, char *argv[])
{
    MatrixXd mat;
    LoadCSV loader;
    mat = loader.load_data("../mat.csv");
    
    std::cout << mat << std::endl;
    mat(1,1) = 350;


    // Solving

    AbstractLinalgSolver<MatrixXd> *pSolver = 0;
    pSolver = new Power<MatrixXd>;

    pSolver->SetMatrix(mat);
    MatrixXd mat2 = pSolver->GetMatrix();
    std::cout << mat2 << std::endl;

    pSolver->SolveEquation();

    delete pSolver;
    WriteCSV writer;
    writer.write_data("../out_mat.csv", mat);
}