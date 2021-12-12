#ifndef LOADCSVHEADERDEF
#define LOADCSVHEADERDEF

#include "input.hpp"

template <typename T> 
class LoadCSV: public Input<T>{
public:
    T LoadData(std::string filename);
};

#endif