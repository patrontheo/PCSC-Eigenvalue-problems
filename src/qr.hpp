#ifndef QRHEADERDEF
#define QRHEADERDEF

#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>
#include "abstract_linalg_solver.hpp"

using namespace Eigen;

/**
 * @brief Daughter class of AbstractLinalgSolver.
 * Class implementing the QR algorithm
 * @tparam Matrix is the templated parameter for matrices in the algorithm
 * @tparam Vector is the templated parameter for vectors in the algorithm
 * @tparam Scalar is the templated parameter for scalars in the algorithm
 */

template <typename Matrix, typename Vector, typename Scalar>
class QR : public AbstractLinalgSolver<Matrix,Vector,Scalar> {
public:
    // Constructor and destructor
    //! A constructor.
    /*!
    Constructs the QR class.
    */
    QR();

    //! A destructor.
    /*!
    Destructs the QR class.
    */
    virtual ~QR();

    //Methods
     //! A method function that solves for all eigenvalues with the QR method
    /*!
    \return All eigenvalues in a vector form
    */
    virtual Vector SolveEquation(); 

};

#endif