#include "load_csv.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace Eigen;

template <typename Matrix>
Matrix LoadCSV<Matrix>::LoadData(std::string filename){

    std::vector<double> entries;
    std::ifstream inputfile(filename);
    std::string row;
    std::string element;
    int count_line(0);

    // To check if the file exists
    if(inputfile.fail()){
        std::cerr << "The specified file does not exist" << std::endl;
        assert(0); //stop the program if the file does not exist
    }
    
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
