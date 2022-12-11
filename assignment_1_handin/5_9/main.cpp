//
//  main.cpp
//  5_9
//
//  Created by Petr Vaněk on 02/05/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//

#include <iostream>
void solve3by3 (double **A, double *b , double *u){
    double det = A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1]) -
                 A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0]) +
                 A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
    assert(det != 0);
    u[0] = (b[0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1]) -
            A[0][1]*(b[1]*A[2][2]-A[1][2]*b[2]) +
            A[0][2]*(b[1]*A[2][1]-A[1][1]*b[2]))/det;
    u[1] = (A[0][0]*(b[1]*A[2][2]-A[1][2]*b[2]) -
            b[0]*(A[1][0]*A[2][2]-A[1][2]*A[2][0]) +
            A[0][2]*(A[1][0]*b[2]-b[1]*A[2][0]))/det;
    u[2] = (A[0][0]*(A[1][1]*b[2]-b[1]*A[2][1]) -
            A[0][1]*(A[1][0]*b[2]-b[1]*A[2][0]) +
            b[0]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]))/det;
    
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
    u[0] = 2.0; u[1] = 12.0; u[2] = 5.0;
    
    A[0][0] = 1.0; A[0][1] = 2.0; A[0][2] = -1.0;
    A[1][0] = 2.0; A[1][1] = 2.0; A[1][2] = 2.0;
    A[2][0] = 1.0; A[2][1] = -1.0; A[2][2] = 2.0;
    
    
    solve3by3(A, b, u);
    std::cout<< u[0] << " " << u[1] << " " << u[2] << "\n";
    
    return 0;
}
