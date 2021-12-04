#ifndef WRITECSVHEADERDEF
#define WRITECSVHEADERDEF

#include "Output.hpp"
using namespace Eigen;

template <typename T> 
class WriteCSV: public Output<T>{
public:
    void write_data(std::string filename, T data);
};

#endif