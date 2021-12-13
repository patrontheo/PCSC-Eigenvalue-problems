#ifndef WRITECSVHEADERDEF
#define WRITECSVHEADERDEF

#include "output.hpp"
using namespace Eigen;

/**
 * @brief Daughter Class of Output.
 * Implement the eigenvalue writing to csv file
 * @tparam Matrix 
 */
template <typename Matrix> 
class WriteCSV: public Output<Matrix>{
public:
    /**
     * @brief Write the computed eigenvalues to a csv file
     * 
     * @param filename 
     * @param data 
     */
    void WriteData(std::string filename, Matrix data);
};

#endif