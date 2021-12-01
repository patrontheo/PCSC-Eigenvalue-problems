#include "WriteCSV.hpp"
#include <vector>
#include <iostream>
#include <fstream>


void WriteCSV::write_data(std::string filename, Eigen::MatrixXd matrix){
    const static Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n");
    std::ofstream outputfile(filename.c_str());
    outputfile << matrix.format(CSVFormat);
}
