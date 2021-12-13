
#ifndef ABSTRACTLINALGSOLVERHEADERDEF
#define ABSTRACTLINALGSOLVERHEADERDEF


#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include <vector>

using namespace Eigen;
/**
 * @brief Abstract Super Class for finding the eigenvalues of the member vector
 * 
 * @tparam Matrix is the templated parameter for matrices in the algorithm
 * @tparam Vector is the templated parameter for vectors in the algorithm
 * @tparam Scalar is the templated parameter for scalars in the algorithm
 */
template <typename Matrix, typename Vector,typename Scalar> 
class AbstractLinalgSolver{
public:

    // Constructor and destructor
    //! A constructor.
    /*!
    Constructs the AbstractLinalgSolver class.
    */
    AbstractLinalgSolver();
    //! A destructor.
    /*!
    Destructs the AbstractLinalgSolver class.
    */
    virtual ~AbstractLinalgSolver();

    // Methods
    //! A method taking a matrix and returning a void.
    /*!
    \param matrix a matrix argument
    */
    void SetMatrix(Matrix matrix);

    //! A method taking a scalar and returning a void.
    /*!
    \param shift a scalar argument
    */
    void SetShift(Scalar shift);

    //! A method taking a double and returning a void.
    /*!
    \param error a double argument
    */
    void SetError(double error);

    //! A method taking no argument and returning a matrix.
    /*!
    \return The member matrix
    */
    Matrix GetMatrix() const { return matrix_; }
    
    
    //! A method taking no argument and returning the threshold error.
    /*!
    \return The member error
    */
    double GetError() const { return error_; }

    //! A pure virtual member.
    /*!
    \return returns a vector
    */
    virtual Vector SolveEquation() = 0;

protected:
    Matrix matrix_; /*!< The matrix used to find the eigenvalues*/
    double error_; /*!< The threshold used to end the algorithms solving for the eigenvalues */
    Scalar shift_; /*!< A scalar containing the value of shift to be applied in the inverse power method */
};

#endif