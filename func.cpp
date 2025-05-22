#include <iostream>
#include <iomanip>
#include <cmath>
#include "func.h"

using namespace std;

void solveEquations(double matrix[][DIMENSION_LIMIT + 1], int rows, int cols) {
    for (int pivot = 0; pivot < rows; ++pivot) {
        if (matrix[pivot][pivot] == 0) {
            bool found = false;
            for (int nextRow = pivot + 1; nextRow < rows; ++nextRow) {
                if (matrix[nextRow][pivot] != 0) {
                    for (int column = 0; column <= cols; ++column)
                        swap(matrix[pivot][column], matrix[nextRow][column]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "⚠️ Error: No unique solution found!\n";
                return;
            }
        }

        double divisor = matrix[pivot][pivot];
        for (int column = 0; column <= cols; ++column)
            matrix[pivot][column] /= divisor;

        for (int currentRow = 0; currentRow < rows; ++currentRow) {
            if (currentRow != pivot) {
                double multiplier = matrix[currentRow][pivot];
                for (int column = 0; column <= cols; ++column)
                    matrix[currentRow][column] -= multiplier * matrix[pivot][column];
            }
        }
    }

    cout << "🔍 Results:\n";
    for (int i = 0; i < rows; ++i)
        cout << "  x" << i + 1 << " = " << fixed << setprecision(6) << matrix[i][cols] << endl;
}

bool getInverse(double inputMatrix[][DIMENSION_LIMIT], double outputMatrix[][DIMENSION_LIMIT], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            outputMatrix[i][j] = (i == j) ? 1 : 0;
        }

    for (int pivot = 0; pivot < size; ++pivot) {
        if (inputMatrix[pivot][pivot] == 0) {
            bool found = false;
            for (int nextRow = pivot + 1; nextRow < size; ++nextRow) {
                if (inputMatrix[nextRow][pivot] != 0) {
                    for (int column = 0; column < size; ++column) {
                        swap(inputMatrix[pivot][column], inputMatrix[nextRow][column]);
                        swap(outputMatrix[pivot][column], outputMatrix[nextRow][column]);
                    }
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }

        double divisor = inputMatrix[pivot][pivot];
        for (int column = 0; column < size; ++column) {
            inputMatrix[pivot][column] /= divisor;
            outputMatrix[pivot][column] /= divisor;
        }

        for (int currentRow = 0; currentRow < size; ++currentRow) {
            if (currentRow != pivot) {
                double multiplier = inputMatrix[currentRow][pivot];
                for (int column = 0; column < size; ++column) {
                    inputMatrix[currentRow][column] -= multiplier * inputMatrix[pivot][column];
                    outputMatrix[currentRow][column] -= multiplier * outputMatrix[pivot][column];
                }
            }
        }
    }

    return true;
}

double calculateDet(double mat[][DIMENSION_LIMIT], int n) {
    double temp[DIMENSION_LIMIT][DIMENSION_LIMIT];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            temp[i][j] = mat[i][j];

    double det = 1;
    for (int pivot = 0; pivot < n; ++pivot) {
        if (temp[pivot][pivot] == 0) {
            bool found = false;
            for (int nextRow = pivot + 1; nextRow < n; ++nextRow) {
                if (temp[nextRow][pivot] != 0) {
                    for (int column = 0; column < n; ++column)
                        swap(temp[pivot][column], temp[nextRow][column]);
                    det *= -1;
                    found = true;
                    break;
                }
            }
            if (!found)
                return 0;
        }

        det *= temp[pivot][pivot];
        for (int currentRow = pivot + 1; currentRow < n; ++currentRow) {
            double factor = temp[currentRow][pivot] / temp[pivot][pivot];
            for (int column = 0; column < n; ++column)
                temp[currentRow][column] -= factor * temp[pivot][column];
        }
    }

    return det;
}