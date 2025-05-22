#ifndef MATRIX_CALCULATIONS_H
#define MATRIX_CALCULATIONS_H

const int DIMENSION_LIMIT = 20;

void solveEquations(double matrix[][DIMENSION_LIMIT + 1], int rows, int cols);
bool getInverse(double inputMatrix[][DIMENSION_LIMIT], double outputMatrix[][DIMENSION_LIMIT], int size);
double calculateDet(double mat[][DIMENSION_LIMIT], int n);

#endif