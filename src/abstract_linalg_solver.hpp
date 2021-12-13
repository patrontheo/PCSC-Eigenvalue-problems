
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
    Constructs the AbstractLinalgSolver class instance.
    */
    AbstractLinalgSolver();
    //! A destructor.
    /*!
    Destructs the AbstractLinalgSolver class instance.
    */
    virtual ~AbstractLinalgSolver();

    // Methods
    //! Set the member matrix_.
    /*!
    \param matrix a Matrix argument
    */
    void SetMatrix(Matrix matrix);

    //! Set the member shift_.
    /*!
    \param shift a Scalar argument
    */
    void SetShift(Scalar shift);

    //! Set the member error_.
    /*!
    \param error a double argument
    */
    void SetError(double error);

    //! Returns the member matrix_
    /*!
    \return The member matrix
    */
    Matrix GetMatrix() const { return matrix_; }
    
    
    //! returns the member error_
    /*!
    \return The member error
    */
    double GetError() const { return error_; }

    //! A pure virtual method defined in sub classes.
    /*!
    \return returns a vector
    */
    virtual Vector SolveEquation() = 0;

protected:
    Matrix matrix_; /*!< The matrix used to find the eigenvalues*/
    double error_; /*!< The threshold used to end the algorithms solving for the eigenvalues */
    Scalar shift_; /*!< A scalar containing the value of the shift to be used in the shifted inverse power method */
};

#endif