#ifndef LOADCSVHEADERDEF
#define LOADCSVHEADERDEF

#include "input.hpp"

template <typename Matrix> 
class LoadCSV: public Input<Matrix>{
public:
    Matrix LoadData(std::string filename);
};

#endif