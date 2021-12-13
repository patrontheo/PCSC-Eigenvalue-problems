#ifndef POWERHEADERDEF
#define POWERHEADERDEF

#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>
#include "abstract_linalg_solver.hpp"

using namespace Eigen;

/**
 * @brief Daughter class of AbstractLinalgSolver
 * Finds the largest eigenvalue of the member matrix with the power method
 * 
 * @tparam Matrix is the templated parameter for matrices in the algorithm
 * @tparam Vector is the templated parameter for vectors in the algorithm
 * @tparam Scalar is the templated parameter for scalars in the algorithm
 */
template <typename Matrix,typename Vector,typename Scalar>
class Power : public AbstractLinalgSolver<Matrix,Vector,Scalar> {
public:
    // Constructor and destructor
    //! A constructor.
    /*!
    Constructs the Power class.
    */
    Power();

    //! A destructor.
    /*!
    Destructs the Power class.
    */
    virtual ~Power();

    //Methods
     //! A method function that solves the largest eigenvalue with the power method
    /*!
    \return The largest eigenvalue in vector form
    */
    virtual Vector SolveEquation(); 

};

#endif