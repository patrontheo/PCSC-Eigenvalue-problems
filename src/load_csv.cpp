#include "load_csv.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace Eigen;

template <typename Matrix>
Matrix LoadCSV<Matrix>::LoadData(std::string filename){

    std::vector<double> entries;
    std::ifstream inputfile(filename);
    std::string row;
    std::string element;
    int count_line(0);
    
    while (getline(inputfile, row)) 
    {
        std::stringstream row_stream(row);
        while (getline(row_stream, element, ','))
        {
            entries.push_back(stod(element));  
        }
        count_line++; 
    }

    int count_column(entries.size() / count_line);

    return Eigen::Map<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>>(entries.data(), count_line, count_column);
}

template class LoadCSV<MatrixXd>;
