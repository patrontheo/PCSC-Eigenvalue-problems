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

// test the power solver
TEST(power, solve3x3) {

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

TEST(power, solve5x5) {

    MatrixXd mat(5, 5);
    mat << 6, 8, 7, 5, 4, 8, 7, 65, 7, 8, 7, 65, 5, 4, 6, 5, 7, 4, 6, 7, 4, 8, 6, 7, 87;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new Power<MatrixXd,VectorXd, double>;

    ptr_solver->SetMatrix(mat);
    ptr_solver->SetError(0.0001);

    VectorXd eigenvalue = ptr_solver->SolveEquation();

    ASSERT_NEAR(93.7509, eigenvalue(0), 1e-3);
}

// test the inverse power solver
TEST(inverse_power, solve3x3) {

    MatrixXd mat(3, 3);
    mat << -2, -4, 2, -2, 1, 2, 4, 2, 5;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new InvPower<MatrixXd,VectorXd, double>;

    ptr_solver->SetMatrix(mat);
    ptr_solver->SetError(0.0001);

    VectorXd eigenvalue = ptr_solver->SolveEquation();

    ASSERT_NEAR(3, eigenvalue(0), 1e-3);
}

TEST(inverse_power, solve5x5) {

    MatrixXd mat(5, 5);
    mat << 6, 8, 7, 5, 4, 8, 7, 65, 7, 8, 7, 65, 5, 4, 6, 5, 7, 4, 6, 7, 4, 8, 6, 7, 87;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new InvPower<MatrixXd,VectorXd, double>;

    ptr_solver->SetMatrix(mat);
    ptr_solver->SetError(0.0001);

    VectorXd eigenvalue = ptr_solver->SolveEquation();

    ASSERT_NEAR(0.883932, eigenvalue(0), 1e-3);
}

// Test the inverse power shifted solver with two different shifts
TEST(inverse_power, shifted_solve3x3) {

    MatrixXd mat(3, 3);
    mat << -2, -4, 2, -2, 1, 2, 4, 2, 5;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new InvPower<MatrixXd,VectorXd, double>;

    ptr_solver->SetMatrix(mat);
    ptr_solver->SetError(0.0001);
    
    //shift of 5 to find eigenvalue 6
    ptr_solver->SetShift(5);
    VectorXd eigenvalue = ptr_solver->SolveEquation();

    ASSERT_NEAR(6, eigenvalue(0), 1e-3);

    //shift of -4 to find eigenvalue -5
    ptr_solver->SetShift(-4);
    eigenvalue = ptr_solver->SolveEquation();

    ASSERT_NEAR(-5, eigenvalue(0), 1e-3);
}

TEST(inverse_power, shifted_solve5x5) {

    MatrixXd mat(5, 5);
    mat << 6, 8, 7, 5, 4, 8, 7, 65, 7, 8, 7, 65, 5, 4, 6, 5, 7, 4, 6, 7, 4, 8, 6, 7, 87;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new InvPower<MatrixXd,VectorXd, double>;

    ptr_solver->SetMatrix(mat);
    ptr_solver->SetError(0.0001);
    
    //shift of 5 to find eigenvalue 7.94752
    ptr_solver->SetShift(5);
    VectorXd eigenvalue = ptr_solver->SolveEquation();

    ASSERT_NEAR(7.94752, eigenvalue(0), 1e-3);

    //shift of -50 to find eigenvalue -59.0857
    ptr_solver->SetShift(-50);
    eigenvalue = ptr_solver->SolveEquation();

    ASSERT_NEAR(-59.0857, eigenvalue(0), 1e-3);
}

//Test the qr solver
TEST(qr, solve3x3) {

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

TEST(qr, solve5x5) {

    MatrixXd mat(5, 5);
    mat << 6, 8, 7, 5, 4, 8, 7, 65, 7, 8, 7, 65, 5, 4, 6, 5, 7, 4, 6, 7, 4, 8, 6, 7, 87;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new QR<MatrixXd,VectorXd, double>;

    ptr_solver->SetMatrix(mat);
    ptr_solver->SetError(0.0001);

    VectorXd eigenvalue = ptr_solver->SolveEquation();
    VectorXd val(5);
    val << 93.7509, 67.5034, -59.0857, 7.94752, 0.883932;

    for(int rows(0); rows < val.rows(); rows++){
        ASSERT_NEAR(val(rows), eigenvalue(rows), 1e-3);
    }
}

// test the matrix loading from csv file
TEST(load_csv, load_matrix) {
    MatrixXd mat(3, 3);
    mat << -2, -4, 2, -2, 1, 2, 4, 2, 5;

    MatrixXd mat2;
    LoadCSV<MatrixXd> loader;
    mat2 = loader.LoadData("../data/mat.csv");

    for(int rows(0); rows < mat.rows(); rows++){
        for(int cols(0); cols < mat.cols(); cols++){
            ASSERT_NEAR(mat(rows, cols), mat2(rows, cols), 1e-13);
        }
    }
}


//Test the Set and Get matrix methods
// We use and instance of the power subclass 
// because abstractlinalgsolver is an abstract class
TEST(abstract_linalg_solver, set_get_matrix) {

    MatrixXd mat(3, 3);
    mat << -2, -4, 2, -2, 1, 2, 4, 2, 5;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new QR<MatrixXd,VectorXd, double>;

    ptr_solver->SetMatrix(mat);
    MatrixXd mat2 = ptr_solver->GetMatrix();

    for(int rows(0); rows < mat.rows(); rows++){
        for(int cols(0); cols < mat.cols(); cols++){
            ASSERT_NEAR(mat(rows, cols), mat2(rows, cols), 1e-13);
        }
    }
}

// Test the Set and Get error methods
// We use and instance of the power subclass 
// because abstractlinalgsolver is an abstract class
TEST(abstract_linalg_solver, set_get_error) {
    double error = 1e-5;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new QR<MatrixXd,VectorXd, double>;

    ptr_solver->SetError(error);
    double error2 = ptr_solver->GetError();

    ASSERT_NEAR(error, error2, 1e-13);
}

// Test the Set and Get shift methods
// We use and instance of the power subclass 
// because abstractlinalgsolver is an abstract class
TEST(abstract_linalg_solver, set_get_shift) {
    double shift = 4.2;

    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    ptr_solver = new QR<MatrixXd,VectorXd, double>;

    ptr_solver->SetShift(shift);
    double shift2 = ptr_solver->GetShift();

    ASSERT_NEAR(shift, shift2, 1e-13);
}