#include "5_9.h"
#include <iostream>


int main(){
    int n = 3;
    double* b = new double [n];
    double* u = new double [n];
    
    double** A = new double* [n];
    for(int i=0; i<n; i++){
        A[i] = new double [n];
    }
    
    b[0] = 2.0; b[1] = 12.0; b[2] = 5.0;
    u[0] = 2.0; u[1] = 12.0; u[2] = 5.0;
    
    A[0][0] = 1.0; A[0][1] = 2.0; A[0][2] = -1.0;
    A[1][0] = 2.0; A[1][1] = 2.0; A[1][2] = 2.0;
    A[2][0] = 1.0; A[2][1] = -1.0; A[2][2] = 2.0;
    
    
    solve3by3(A, b, u);
    std::cout<< u[0] << " " << u[1] << " " << u[2] << "\n";
	return 0;
}
