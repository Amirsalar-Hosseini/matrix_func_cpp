#include <iostream>
#include <iomanip>
#include "func.h"

using namespace std;

int main() {
    while (true) {
        cout << "\n🔢 Matrix Calculator Menu:\n";
        cout << "1. Solve Linear Equations\n";
        cout << "2. Find Matrix Inverse\n";
        cout << "3. Calculate Determinant\n";
        cout << "0. Exit Program\n";
        cout << "------------------------\n";
        cout << "Enter your selection: ";

        int menuChoice;
        cin >> menuChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "❌ Invalid input. Please enter a number.\n";
            continue;
        }

        switch (menuChoice) {
            case 1: {
                int equationCount, variableCount;
                double equationMatrix[DIMENSION_LIMIT][DIMENSION_LIMIT + 1];

                cout << "\nEnter number of equations: ";
                cin >> equationCount;
                cout << "Enter number of variables: ";
                cin >> variableCount;

                if (equationCount <= 0 || variableCount <= 0 || equationCount > DIMENSION_LIMIT || variableCount > DIMENSION_LIMIT) {
                    cout << "⚠️ Error: Dimensions must be between 1 and " << DIMENSION_LIMIT << ".\n";
                    break;
                }

                cout << "Enter matrix coefficients:\n";
                for (int i = 0; i < equationCount; ++i) {
                    cout << "Row " << i + 1 << ": ";
                    for (int j = 0; j <= variableCount; ++j)
                        cin >> equationMatrix[i][j];
                }

                solveEquations(equationMatrix, equationCount, variableCount);
                break;
            }

            case 2: {
                int matrixSize;
                double inputMat[DIMENSION_LIMIT][DIMENSION_LIMIT], inverseMat[DIMENSION_LIMIT][DIMENSION_LIMIT];

                cout << "\nEnter matrix dimension: ";
                cin >> matrixSize;

                if (matrixSize <= 0 || matrixSize > DIMENSION_LIMIT) {
                    cout << "⚠️ Error: Size must be between 1 and " << DIMENSION_LIMIT << ".\n";
                    break;
                }

                cout << "Enter matrix elements:\n";
                for (int i = 0; i < matrixSize; ++i)
                    for (int j = 0; j < matrixSize; ++j)
                        cin >> inputMat[i][j];

                if (getInverse(inputMat, inverseMat, matrixSize)) {
                    cout << "🔢 Inverse Matrix:\n";
                    for (int i = 0; i < matrixSize; ++i) {
                        for (int j = 0; j < matrixSize; ++j)
                            cout << fixed << setprecision(6) << inverseMat[i][j] << " ";
                        cout << endl;
                    }
                } else {
                    cout << "⚠️ Error: Matrix is not invertible.\n";
                }
                break;
            }

            case 3: {
                int matSize;
                double detMatrix[DIMENSION_LIMIT][DIMENSION_LIMIT];

                cout << "\nEnter matrix size: ";
                cin >> matSize;

                if (matSize <= 0 || matSize > DIMENSION_LIMIT) {
                    cout << "⚠️ Error: Size must be between 1 and " << DIMENSION_LIMIT << ".\n";
                    break;
                }

                cout << "Enter matrix elements:\n";
                for (int i = 0; i < matSize; ++i)
                    for (int j = 0; j < matSize; ++j)
                        cin >> detMatrix[i][j];

                double detValue = calculateDet(detMatrix, matSize);
                cout << "🔢 Determinant Value: " << fixed << setprecision(6) << detValue << endl;
                break;
            }

            case 0:
                cout << "👋 Exiting program. Goodbye!\n";
                return 0;

            default:
                cout << "❌ Invalid choice. Please select between 0 and 3.\n";
        }
    }

    return 0;
}