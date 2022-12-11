
#include <iostream>
#include "5_9.h"


void solve3by3(double **A, double *b, double *u){
    double det = A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1]) -
    A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0]) +
    A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
    
    
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
