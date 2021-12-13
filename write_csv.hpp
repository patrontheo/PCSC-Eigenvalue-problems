#ifndef WRITECSVHEADERDEF
#define WRITECSVHEADERDEF

#include "output.hpp"
using namespace Eigen;

template <typename Matrix> 
class WriteCSV: public Output<Matrix>{
public:
    void WriteData(std::string filename, Matrix data);
};

#endif