#include "LoadCSV.hpp"
#include <vector>
#include <iostream>
#include <fstream>

Eigen::MatrixXd LoadCSV::load_data(std::string filename){

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
