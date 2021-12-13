#ifndef INPUTHEADERDEF
#define INPUTHEADERDEF

#include <string>
#include <iostream>
#include <Eigen/Dense>

/**
 * @brief Abstract super-class for loading input matrix.
 * This class contain only the method LoadData which returns
 * the loaded matrix
 * @tparam Matrix is the templated parameter for input matrix
 */
template <typename Matrix> 
class Input{
public:
    /**
     * @brief Virtual pure method for loading data
     * 
     * @param filename 
     * @return Matrix, the loaded matrix
     */
    virtual Matrix LoadData(std::string filename) = 0;
};

#endif