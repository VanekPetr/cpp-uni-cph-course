#include "5_6.h"
#include <iostream>


int main(){
    int rows = 2;
    int cols = 2;
    double constant = 2.0;
    double* res = new double [rows];
    double* a = new double [rows];
    double* b = new double [cols];
    double** A = new double* [rows];
    double** B = new double* [rows];
    double** res1 = new double* [rows];
    for(int i=0; i<rows; i++){
        A[i] = new double [cols];
        B[i] = new double [cols];
        res1[i] = new double [cols];
    }
    a[0] = 1.0; a[1] = 2.0;
    b[0] = 2.0; b[1] = 1.0;
    A[0][0] = 2.0; A[0][1] = 1.0;
    A[1][0] = 3.0; A[1][1] = 2.0;
    B[0][0] = 1.0; B[0][1] = 2.0;
    B[1][0] = 3.0; B[1][1] = 2.0;
    
    Multiply(res1, A, B, rows, cols, rows, cols);
    std::cout<< res1[0][0] << " " << res1[0][1] << "\n";
    std::cout<< res1[1][0] << " " << res1[1][1] << "\n";
    Multiply(A, constant, B, rows, cols);
    std::cout<< A[0][0] << " " << A[0][1] << "\n";
    std::cout<< A[1][0] << " " << A[1][1] << "\n";
    Multiply(B, A, constant, rows, cols);
    std::cout<< B[0][0] << " " << B[0][1] << "\n";
    std::cout<< B[1][0] << " " << B[1][1] << "\n";
    Multiply(res, a, A, cols, rows, cols);
    std::cout<< res[0] << " " << res[1] << "\n";
    res[0] = 0.0; res[1] = 0.0;
    Multiply(res, B, b, rows, cols, rows);
    std::cout<< res[0] << " " << res[1] << "\n";
    
	return 0;
}
