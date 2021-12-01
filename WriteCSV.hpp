#ifndef WRITECSVHEADERDEF
#define WRITECSVHEADERDEF

#include "Output.hpp"

class WriteCSV: public Output{
public:
    void write_data(std::string filename, Eigen::MatrixXd matrix);
};

#endif