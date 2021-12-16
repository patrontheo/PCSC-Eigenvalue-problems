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
    // Default variables
    double shift = 0;
    double error = 0.0001;
    std::string method = "power";
    std::string filename = "../data/mat.csv";
    std::string extension = "csv";
    
    //Variable used for parsing command line arguments
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
            // Shift
            case 's':
                shift = atof(optarg);
            break;

            // Method
            case 'm':
                method = optarg;
            break;

            // Filename
            case 'f':
                filename = optarg;
                filename = "../data/" + filename;
                if(filename.substr(filename.find_last_of(".") + 1) != "csv") {
                    extension = filename.substr(filename.find_last_of(".") + 1);
                } 
            break;

            // Error
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
    
    // Define matrix 
    MatrixXd mat;

    // Define pointer to input class
    Input<MatrixXd> *ptr_input = 0;
    if (strcmp(extension.c_str(), "csv") != 0){
        std::cerr << "The extension of your input file is not supported. Aborting..";
        return 1;
    } 
    else{
        ptr_input = new LoadCSV<MatrixXd>;
    }

    // Load matrix
    mat = ptr_input->LoadData(filename);

    // Create pointer to abstract class and instanciate solver
    AbstractLinalgSolver<MatrixXd, VectorXd,double> *ptr_solver = 0;
    if (strcmp(method.c_str(), "inversepower") == 0) ptr_solver = new InvPower<MatrixXd,VectorXd, double>;
    else if (strcmp(method.c_str(), "qr") == 0) ptr_solver = new QR<MatrixXd,VectorXd, double>;
    else {
        ptr_solver = new Power<MatrixXd,VectorXd, double>;
        method = "power";
    }

    // print to show chosen options
    std::cout << "filename: " << filename << std::endl;
    std::cout << "method: " << method << std::endl;
    std::cout << "shift: " << shift << std::endl;
    std::cout << "error: " << error << std::endl;

    // Set parameters
    ptr_solver->SetMatrix(mat);
    ptr_solver->SetError(error);
    ptr_solver->SetShift(shift);

    // Solve for eigenvalues
    VectorXd eigenvalue = ptr_solver->SolveEquation();

    // Delete pointers
    delete ptr_input;
    delete ptr_solver;

    // Write to file
    WriteCSV<VectorXd> writer;
    writer.WriteData("../data/eigenvalues.csv", eigenvalue);

    return 0;
}