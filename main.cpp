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
    int method = 0;

    int c;

    while (1)
        {
        static struct option long_options[] =
            {
            {"method",   required_argument,       0, 'm'},
            {"shift",   required_argument,       0, 's'}
            };
        /* getopt_long stores the option index here. */
        int option_index = 0;

        c = getopt_long (argc, argv, "m:s:",
                        long_options, &option_index);

        /* Detect the end of the options. */
        if (c == -1)
            break;

        switch (c)
            {
            case 's':
                shift = atof(optarg);
            break;

            case 'm':
                if(strcmp(optarg, "power") == 0) method = 0;
                if(strcmp(optarg, "inversepower") == 0) method = 1;
                if(strcmp(optarg, "QR") == 0) method = 2;
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


    std::cout << "method: " << method << std::endl;
    std::cout << "shift: " << shift << std::endl;

    MatrixXd mat;
    LoadCSV<MatrixXd> loader;
    mat = loader.load_data("../mat.csv");
    
    std::cout << mat << std::endl;
    // mat(1,1) = 350;    

    // Solving
    AbstractLinalgSolver<MatrixXd, VectorXd,double> *pSolver = 0;

    switch (method)
    {
    case 0:
        pSolver = new Power<MatrixXd,VectorXd, double>;
        break;
    case 1:
        pSolver = new InvPower<MatrixXd,VectorXd, double>;
        break;
    case 2:
        pSolver = new QR<MatrixXd,VectorXd, double>;
        break;
        
    default:
        pSolver = new Power<MatrixXd,VectorXd, double>;
        break;
    }

    // Set parameters
    pSolver->SetMatrix(mat);
    pSolver->SetShift(shift);
    pSolver->SetError(0.0001);

    VectorXd eigenvalue = pSolver->SolveEquation();

    std::cout << eigenvalue << std::endl;
    delete pSolver;
    //WriteCSV<double> writer;
    //writer.write_data("../out_mat.csv", eigenvalue);
}