#ifndef MATRIXMATH_H
#define MATRIXMATH_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void read_file(ifstream& instream, int matrix1[][100], int& rows1, int& cols1, 
               int matrix2[][100], int& rows2, int& cols2);

void matrix_mult(int matrix1[][100], int rows1, int cols1, 
                 int matrix2[][100], int rows2, int cols2, 
                 int result[][100], int& result_rows, int& result_cols);

void print_matrix_to_file(ofstream& outstream, int matrix[][100], int rows, int cols);

#endif