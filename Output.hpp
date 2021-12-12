#ifndef OUTPUTHEADERDEF
#define OUTPUTHEADERDEF

#include <string>
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

template <typename T> 
class Output{
public:
    virtual void WriteData(std::string filename, T data) = 0;
};



#endif