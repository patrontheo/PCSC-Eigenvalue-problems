#include "write_csv.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace Eigen;

template <typename T> 
void WriteCSV<T>::WriteData(std::string filename, T data){
    const static IOFormat CSVFormat(StreamPrecision, DontAlignCols, ", ", "\n");
    std::ofstream outputfile(filename.c_str());
    outputfile << data;//.format(CSVFormat);
}

template class WriteCSV<MatrixXd>;
template class WriteCSV<double>;
