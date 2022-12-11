//
//  main.cpp
//  5_10
//
//  Created by Petr Vaněk on 02/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>
#include "cmath"

void guassian_elimination(double **A, double *b, double *u, int n){
    for(int i=0; i<n; i++){
        A[i][n] = b[i];
    }
    
    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }
        
        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }
        
        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }
    
    // Solve equation Ax=b for an upper triangular matrix A
    for (int i=n-1; i>=0; i--) {
        u[i] = A[i][n]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * u[i];
        }
    }
}


int main(int argc, const char * argv[]) {
    int n = 3;
    double* b = new double [n];
    double* u = new double [n];
    
    double** A = new double* [n];
    for(int i=0; i<n; i++){
        A[i] = new double [n];
    }
    
    b[0] = 2.0; b[1] = 12.0; b[2] = 5.0;
    u[0] = 0.0; u[1] = 0.0; u[2] = 0.0;
    
    A[0][0] = 1.0; A[0][1] = 2.0; A[0][2] = -1.0;
    A[1][0] = 2.0; A[1][1] = 2.0; A[1][2] = 2.0;
    A[2][0] = 1.0; A[2][1] = -1.0; A[2][2] = 2.0; 
    
    
    guassian_elimination(A, b, u, n);
    std::cout<< u[0] << " " << u[1] << " " << u[2] << "\n";
}
