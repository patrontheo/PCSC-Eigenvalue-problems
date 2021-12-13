#ifndef LOADCSVHEADERDEF
#define LOADCSVHEADERDEF

#include "input.hpp"

/**
 * @brief Daughter Class of Input.
 * Implement the matrix loading from cvs file
 * @tparam Matrix 
 */
template <typename Matrix> 
class LoadCSV: public Input<Matrix>{
public:
    /**
     * @brief Load the desired matrix from a csv file
     * 
     * @param filename name of the file from which to load the matrix
     * @return Matrix the read matrix
     */
    Matrix LoadData(std::string filename);
};

#endif