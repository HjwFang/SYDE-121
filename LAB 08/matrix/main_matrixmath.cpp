#include "matrixmath.h"

int main() {
    string ifile, ofile;
    cout << "Enter 1 input file and 1 output file: ";
    cin >> ifile >> ofile;

    ifstream instream(ifile);
    if (instream.fail()) {
        return 1;
    }

    ofstream outstream(ofile);
    if (outstream.fail()) {
        return 1;
    }
    
    // Declare matrices with maximum size
    int matrix1[100][100];
    int matrix2[100][100];
    int result[100][100];
    int rows1, cols1, rows2, cols2;
    int result_rows, result_cols;
    
    // Read both matrices from file
    read_file(instream, matrix1, rows1, cols1, matrix2, rows2, cols2);
    
    // Validate: check if dimensions are valid (not > 100)
    if (rows1 > 100 || cols1 > 100 || rows2 > 100 || cols2 > 100) {
        return 1;
    }
    
    // Validate: check if matrices can be multiplied
    // For A × B, cols of A must equal rows of B
    if (cols1 != rows2) {
        return 1;
    }
    
    // Multiply the matrices
    matrix_mult(matrix1, rows1, cols1, matrix2, rows2, cols2, result, result_rows, result_cols);
    
    // Write result to output file
    print_matrix_to_file(outstream, result, result_rows, result_cols);
    
    instream.close();
    outstream.close();
    
    return 0;
}