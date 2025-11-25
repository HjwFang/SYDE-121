#include "matrixmath.h"

void read_file(ifstream& instream, int matrix1[][100], int& rows1, int& cols1, 
               int matrix2[][100], int& rows2, int& cols2) {
    // Read first matrix dimensions
    instream >> rows1 >> cols1;
    
    // Validate first matrix dimensions
    if (rows1 > 100 || cols1 > 100) {
        return;
    }
    
    // Read first matrix elements
    for (int r = 0; r < rows1; ++r) {
        for (int c = 0; c < cols1; ++c) {
            instream >> matrix1[r][c];
        }
    }
    
    // Read second matrix dimensions
    instream >> rows2 >> cols2;
    
    // Validate second matrix dimensions
    if (rows2 > 100 || cols2 > 100) {
        return;
    }
    
    // Read second matrix elements
    for (int r = 0; r < rows2; ++r) {
        for (int c = 0; c < cols2; ++c) {
            instream >> matrix2[r][c];
        }
    }
}

void matrix_mult(int matrix1[][100], int rows1, int cols1, 
                 int matrix2[][100], int rows2, int cols2, 
                 int result[][100], int& result_rows, int& result_cols) {
    // Matrix multiplication: A(m×n) × B(n×p) = C(m×p)
    // cols1 must equal rows2
    
    result_rows = rows1;
    result_cols = cols2;
    
    // Perform multiplication
    for (int r = 0; r < result_rows; ++r) {
        for (int c = 0; c < result_cols; ++c) {
            result[r][c] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[r][c] += matrix1[r][k] * matrix2[k][c];
            }
        }
    }
}

void print_matrix_to_file(ofstream& outstream, int matrix[][100], int rows, int cols) {
    // Use the exact format from instructions
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            outstream << matrix[r][c] << " ";
        }
        outstream << endl;
    }
}