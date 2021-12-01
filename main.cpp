#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>

#include "AbstractLinalgSolver.hpp"
#include "Power.hpp"

using Eigen::MatrixXd;
using Eigen::Matrix3d;

class Input{
public:
    virtual MatrixXd load_data(std::string filename) = 0;
};

class Load_CSV: public Input{
public:
    MatrixXd load_data(std::string filename){

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
};


class Output{
public:
    virtual void write_data(std::string filename, MatrixXd matrix) = 0;
};

class Write_CSV: public Output{
public:
    virtual void write_data(std::string filename, MatrixXd matrix){
        const static Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n");
        std::ofstream outputfile(filename.c_str());
        outputfile << matrix.format(CSVFormat);
    }

};

int main(int argc, char *argv[])
{
    MatrixXd mat;
    Load_CSV loader;
    mat = loader.load_data("../mat.csv");
    
    std::cout << mat << std::endl;
    mat(1,1) = 350;


    // Solving

    AbstractLinalgSolver<MatrixXd> *pSolver = 0;
    pSolver = new Power<MatrixXd>;

    pSolver->SetMatrix(mat);
    MatrixXd mat2 = pSolver->GetMatrix();
    std::cout << mat2 << std::endl;

    pSolver->SolveEquation();

    delete pSolver;
    Write_CSV writer;
    writer.write_data("../out_mat.csv", mat);
}