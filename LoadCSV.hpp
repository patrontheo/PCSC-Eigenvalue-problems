#ifndef LOADCSVHEADERDEF
#define LOADCSVHEADERDEF

#include "Input.hpp"

class LoadCSV: public Input{
public:
    Eigen::MatrixXd load_data(std::string filename);
};

#endif