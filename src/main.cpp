#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>
#include <stdlib.h>     /* atof */
#include "getopt.h"

#include "abstract_linalg_solver.hpp"
#include "power.hpp"
#include "input.hpp"
#include "load_csv.hpp"
#include "output.hpp"
#include "write_csv.hpp"
#include "inv_power.hpp"
#include "qr.hpp"

using namespace Eigen;

int main(int argc, char *argv[])
{   
    double shift = 0;
    double error = 0.0001;
    std::string method = "power";
    std::string filename = "../data/mat.csv";

    int command;

    while (1)
        {
        static struct option long_options[] =
            {
            {"method",   required_argument,       0, 'm'},
            {"shift",   required_argument,       0, 's'},
            {"filename",   required_argument,       0, 'f'},
            {"error",   required_argument,       0, 'e'}
            };
        /* getopt_long stores the option index here. */
        int option_index = 0;

        command = getopt_long (argc, argv, "m:s:f:e:",
                        long_options, &option_index);

        /* Detect the end of the options. */
        if (command == -1)
            break;

        switch (command)
            {
            case 's':
                shift = atof(optarg);
            break;

            case 'm':
                method = optarg;
            break;

            case 'f':
                filename = optarg;
                filename = "../data/" + filename;
            break;

            case 'e':
                error = atof(optarg);
            break;

            default:
                abort ();
            }
        }

    /* Print any remaining command line arguments (not options). */
    if (optind < argc)
        {
        printf ("non-option ARGV-elements: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        putchar ('\n');
        }
    

    MatrixXd mat;
    LoadCSV<MatrixXd> loader;
    mat = loader.LoadData(filename);

    // Solving
    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;

    if (strcmp(method.c_str(), "inversepower") == 0) ptr_solver = new InvPower<MatrixXd,VectorXd, double>;
    else if (strcmp(method.c_str(), "qr") == 0) ptr_solver = new QR<MatrixXd,VectorXd, double>;
    else {
        ptr_solver = new Power<MatrixXd,VectorXd, double>;
        method = "power";
    }

    std::cout << "filename: " << filename << std::endl;
    std::cout << "method: " << method << std::endl;
    std::cout << "shift: " << shift << std::endl;
    std::cout << "error: " << error << std::endl;
    std::cout << "input matrix:" << std::endl << mat << std::endl;

    // Set parameters
    ptr_solver->SetMatrix(mat);
    ptr_solver->SetShift(shift);
    ptr_solver->SetError(error);

    VectorXd eigenvalue = ptr_solver->SolveEquation();

    std::cout << "eigenvalue(s):" << std::endl << eigenvalue << std::endl;
    
    delete ptr_solver;

    WriteCSV<VectorXd> writer;
    writer.WriteData("../data/eigenvalues.csv", eigenvalue);
}