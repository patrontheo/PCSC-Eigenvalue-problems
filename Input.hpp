#ifndef INPUTHEADERDEF
#define INPUTHEADERDEF

#include <string>
#include <iostream>
#include <Eigen/Dense>

class Input{
public:
    virtual Eigen::MatrixXd load_data(std::string filename) = 0;
};

#endif