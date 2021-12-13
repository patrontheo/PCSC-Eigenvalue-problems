#ifndef OUTPUTHEADERDEF
#define OUTPUTHEADERDEF

#include <string>
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

/**
 * @brief Abstract super-class for writing eigenvalues.
 * This class contain only the method WriteData which write
 * the eigenvalues to output file
 * @tparam Vector the vector of found eigenvalues 
 */
template <typename Matrix> 
class Output{
public:
    /**
     * @brief Virtual pure method for writing eigenvalues
     * 
     * @param filename name of the created output file
     * @param data Vector of eigenvalues to write in the file
     */
    virtual void WriteData(std::string filename, Matrix data) = 0;
};



#endif