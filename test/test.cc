#include <cmath>
#include <gtest/gtest.h>
#include <Eigen/Dense>
#include "../src/abstract_linalg_solver.hpp"
#include "../src/power.hpp"
#include "../src/input.hpp"
#include "../src/load_csv.hpp"
#include "../src/output.hpp"
#include "../src/write_csv.hpp"
#include "../src/inv_power.hpp"
#include "../src/qr.hpp"	

using namespace Eigen;

TEST(Power, matrice) {

    MatrixXd mat(3, 3);
    mat << -2, -4, 2, -2, 1, 2, 4, 2, 5;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new Power<MatrixXd,VectorXd, double>;

    ptr_solver->SetMatrix(mat);
    ptr_solver->SetError(0.0001);

    VectorXd eigenvalue = ptr_solver->SolveEquation();
    VectorXd val(1);
    val << eigenvalue;

    ASSERT_NEAR(6, eigenvalue(0), 1e-3);
}

TEST(InversePower, matrice) {

    MatrixXd mat(3, 3);
    mat << -2, -4, 2, -2, 1, 2, 4, 2, 5;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new InvPower<MatrixXd,VectorXd, double>;

    ptr_solver->SetMatrix(mat);
    ptr_solver->SetError(0.0001);

    VectorXd eigenvalue = ptr_solver->SolveEquation();
    VectorXd val(1);
    val << eigenvalue;

    ASSERT_NEAR(3, eigenvalue(0), 1e-3);
}

TEST(InversePowerShifted, matrice) {

    MatrixXd mat(3, 3);
    mat << -2, -4, 2, -2, 1, 2, 4, 2, 5;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new InvPower<MatrixXd,VectorXd, double>;

    ptr_solver->SetMatrix(mat);
    ptr_solver->SetError(0.0001);
    ptr_solver->SetShift(5);

    VectorXd eigenvalue = ptr_solver->SolveEquation();
    VectorXd val(1);
    val << eigenvalue;

    ASSERT_NEAR(6, eigenvalue(0), 1e-3);
}

TEST(qr, matrice) {

    MatrixXd mat(3, 3);
    mat << -2, -4, 2, -2, 1, 2, 4, 2, 5;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new QR<MatrixXd,VectorXd, double>;

    ptr_solver->SetMatrix(mat);
    ptr_solver->SetError(0.0001);

    VectorXd eigenvalue = ptr_solver->SolveEquation();
    VectorXd val(3);
    val << 6, -5, 3;

    ASSERT_NEAR(val(0), eigenvalue(0), 1e-3);
    ASSERT_NEAR(val(1), eigenvalue(1), 1e-3);
    ASSERT_NEAR(val(2), eigenvalue(2), 1e-3);
}