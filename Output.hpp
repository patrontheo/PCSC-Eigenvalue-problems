#ifndef OUTPUTHEADERDEF
#define OUTPUTHEADERDEF

#include <string>
#include <iostream>
#include <Eigen/Dense>

class Output{
public:
    virtual void write_data(std::string filename, Eigen::MatrixXd matrix) = 0;
};

#endif