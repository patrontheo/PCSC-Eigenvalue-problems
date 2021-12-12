#ifndef WRITECSVHEADERDEF
#define WRITECSVHEADERDEF

#include "output.hpp"
using namespace Eigen;

template <typename T> 
class WriteCSV: public Output<T>{
public:
    void WriteData(std::string filename, T data);
};

#endif