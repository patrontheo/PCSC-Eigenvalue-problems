#ifndef OUTPUTHEADERDEF
#define OUTPUTHEADERDEF

#include <string>
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

template <typename Matrix> 
class Output{
public:
    virtual void WriteData(std::string filename, Matrix data) = 0;
};



#endif