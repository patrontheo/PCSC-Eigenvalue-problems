#include <cmath>
#include <gtest/gtest.h>
#include <Eigen/Dense>
#include "../abstract_linalg_solver.hpp"
#include "../power.hpp"
#include "../input.hpp"
#include "../load_csv.hpp"
#include "../output.hpp"
#include "../write_csv.hpp"
#include "../inv_power.hpp"
#include "../qr.hpp"	

using namespace Eigen;

TEST(SolveEquation, matrice) {
    // MatrixXd mat;
    // LoadCSV<MatrixXd> loader;
    // mat = loader.LoadData("../mat.csv");
    // std::cout << mat << std::endl;
    MatrixXf mat(3, 3);
    mat << -2, -4, 2, -2, 1, 2, 4, 2, 5;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new Power<MatrixXd,VectorXd, double>;

    // ptr_solver->SetMatrix(mat);
    // ptr_solver->SetShift(0);
    // ptr_solver->SetError(0.0001);

    // VectorXd eigenvalue = ptr_solver->SolveEquation();
    // VectorXd val(1);
    // val << eigenvalue;

    // ASSERT_NEAR(val(1), eigenvalue(1), 1e-1);
}
