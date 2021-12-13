#ifndef INVPOWERHEADERDEF
#define INVPOWERHEADERDEF

#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>
#include "abstract_linalg_solver.hpp"

using namespace Eigen;

/**
 * @brief Daughter Class of AbstractlinalgSolver
 * Finds the smallest eigenvalue of the member matrix
 * @tparam Matrix 
 * @tparam Vector 
 * @tparam Scalar 
 */

template <typename Matrix,typename Vector,typename Scalar>
class InvPower : public AbstractLinalgSolver<Matrix,Vector,Scalar> {
public:
    // Constructor and destructor
    //! A constructor.
    /*!
    Constructs the InvPower class.
    */
    InvPower();
    //! A destructor.
    /*!
    Destructs the InvPower class.
    */
    virtual ~InvPower();

    // Methods
     //! A method function that solves the smallest eigenvalue with the inverse power method
    /*!
    \return The smallest eigenvalue in vector form
    */
    virtual Vector SolveEquation(); 

};

#endif