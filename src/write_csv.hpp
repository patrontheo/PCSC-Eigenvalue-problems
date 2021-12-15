#ifndef WRITECSVHEADERDEF
#define WRITECSVHEADERDEF

#include "output.hpp"
using namespace Eigen;

/**
 * @brief Daughter Class of Output.
 * Implement the eigenvalue writing to csv file
 * @tparam Vector the vector of found eigenvalues 
 */
template <typename Vector> 
class WriteCSV: public Output<Vector>{
public:
    // Constructor and destructor
    //! A constructor.
    /*!
    Constructs the WriteCSV class instance.
    */
    WriteCSV(){};

    //! A destructor.
    /*!
    Destructs the WriteCSV class instance.
    */
    virtual ~WriteCSV(){};

    /**
     * @brief Write the computed eigenvalues to a csv file
     * 
     * @param filename name of the created output file
     * @param data Vector of eigenvalues to write in the file
     */
    void WriteData(std::string filename, Vector data);
};

#endif