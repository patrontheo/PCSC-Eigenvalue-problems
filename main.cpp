#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>
// #include <cstring>
#include <stdlib.h>     /* atoi */

#include "AbstractLinalgSolver.hpp"
#include "Power.hpp"
#include "Input.hpp"
#include "LoadCSV.hpp"
#include "Output.hpp"
#include "WriteCSV.hpp"
#include "getopt.h"

using namespace Eigen;

// static int verbose_flag;

int main(int argc, char *argv[])
{   
    double shift = 0;
    int method = 0;

    int c;

    while (1)
        {
        static struct option long_options[] =
            {
            /* These options set a flag. */
            // {"verbose", no_argument,       &verbose_flag, 1},
            // {"brief",   no_argument,       &verbose_flag, 0},
            {"method",   required_argument,       0, 'm'},
            {"shift",   required_argument,       0, 's'}
            /* These options don’t set a flag.
                We distinguish them by their indices. */
            // {"add",     no_argument,       0, 'a'},
            // {"append",  no_argument,       0, 'b'},
            // {"delete",  required_argument, 0, 'd'},
            // {"create",  required_argument, 0, 'c'},
            // {"file",    required_argument, 0, 'f'},
            // {0, 0, 0, 0}
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
            case 0:
            /* If this option set a flag, do nothing else now. */
            if (long_options[option_index].flag != 0)
                break;
            printf ("option %s", long_options[option_index].name);
            if (optarg)
                printf (" with arg %s", optarg);
            printf ("\n");
            break;

            // case 'a':
            // puts ("option -a\n");
            // break;

            // case 'b':
            // puts ("option -b\n");
            // break;

            // case 'c':
            // printf ("option -c with value `%s'\n", optarg);
            // break;

            // case 'd':
            // printf ("option -d with value `%s'\n", optarg);
            // break;

            case 's':
            shift = atof(optarg);
            break;

            case 'm':
            if(strcmp(optarg, "power") == 0) method = 0;
            if(strcmp(optarg, "inversepower") == 0) method = 1;
            if(strcmp(optarg, "QR") == 0) method = 2;
            break;

            case '?':
            /* getopt_long already printed an error message. */
            break;

            default:
            abort ();
            }
        }

    /* Instead of reporting ‘--verbose’
        and ‘--brief’ as they are encountered,
        we report the final status resulting from them. */
    // if (verbose_flag)
    //     puts ("verbose flag is set");

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
    AbstractLinalgSolver<MatrixXd> *pSolver = 0;
    pSolver = new Power<MatrixXd>;



    // Set parameters
    pSolver->SetMatrix(mat);
    pSolver->SetError(0.001);

    double eigenvalue = pSolver->SolveEquation();
    // double eigenvalue = shifted(mat, 1., pSolver);

    std::cout << eigenvalue << std::endl;
    delete pSolver;
    WriteCSV<double> writer;
    writer.write_data("../out_mat.csv", eigenvalue);
}