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
 * @brief Daughter Class of AbstractlinalgSolver.
 * Class implementing the inverse power method
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
    Constructs the InvPower class instance.
    */
    InvPower();
    //! A destructor.
    /*!
    Destructs the InvPower class instance.
    */
    virtual ~InvPower();

    // Methods
     //! A method function that returns the smallest eigenvalue with the inverse power method
    /*!
    \return The smallest eigenvalue as a vector of one element
    */
    virtual Vector SolveEquation(); 

};

#endif