#ifndef INPUTHEADERDEF
#define INPUTHEADERDEF

#include <string>
#include <iostream>
#include <Eigen/Dense>

template <typename T> 
class Input{
public:
    virtual T load_data(std::string filename) = 0;
};

#endif