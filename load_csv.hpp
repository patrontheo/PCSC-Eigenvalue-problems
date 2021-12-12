#ifndef LOADCSVHEADERDEF
#define LOADCSVHEADERDEF

#include "Input.hpp"

template <typename T> 
class LoadCSV: public Input<T>{
public:
    T load_data(std::string filename);
};

#endif