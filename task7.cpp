#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix createMatrix(int n) {
    return Matrix(n, vector<int>(n, 0));
}

Matrix add(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C = createMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix subtract(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C = createMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// normal way of multiplying two matrices
Matrix naiveMultiply(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C = createMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// strassen's method, uses 7 multiplications instead of 8
Matrix strassenMultiply(Matrix A, Matrix B) {
    int n = A.size();

    // if matrix is small just use normal multiplication
    if (n <= 2) {
        return naiveMultiply(A, B);
    }

    int half = n / 2;
    Matrix A11 = createMatrix(half), A12 = createMatrix(half);
    Matrix A21 = createMatrix(half), A22 = createMatrix(half);
    Matrix B11 = createMatrix(half), B12 = createMatrix(half);
    Matrix B21 = createMatrix(half), B22 = createMatrix(half);

    // split each matrix into 4 smaller parts
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    Matrix M1 = strassenMultiply(add(A11, A22), add(B11, B22));
    Matrix M2 = strassenMultiply(add(A21, A22), B11);
    Matrix M3 = strassenMultiply(A11, subtract(B12, B22));
    Matrix M4 = strassenMultiply(A22, subtract(B21, B11));
    Matrix M5 = strassenMultiply(add(A11, A12), B22);
    Matrix M6 = strassenMultiply(subtract(A21, A11), add(B11, B12));
    Matrix M7 = strassenMultiply(subtract(A12, A22), add(B21, B22));

    Matrix C11 = add(subtract(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(subtract(add(M1, M3), M2), M6);

    // put the 4 parts back together into one matrix
    Matrix C = createMatrix(n);
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }

    return C;
}

void printMatrix(Matrix M) {
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M.size(); j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

bool matricesEqual(Matrix A, Matrix B) {
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A.size(); j++)
            if (A[i][j] != B[i][j]) return false;
    return true;
}

Matrix randomMatrix(int n) {
    Matrix M = createMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = rand() % 10;
    return M;
}

int main() {
    srand(time(0));

    // test 1: 2x2 matrices
    Matrix A2 = {{1, 2}, {3, 4}};
    Matrix B2 = {{5, 6}, {7, 8}};
    Matrix result2 = strassenMultiply(A2, B2);
    cout << "Test 1 (2x2):" << endl;
    printMatrix(result2);
    cout << "Matches naive? " << (matricesEqual(result2, naiveMultiply(A2, B2)) ? "yes" : "no") << endl << endl;

    // test 2: 4x4 matrices
    Matrix A4 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Matrix B4 = {{16,15,14,13},{12,11,10,9},{8,7,6,5},{4,3,2,1}};
    Matrix result4 = strassenMultiply(A4, B4);
    cout << "Test 2 (4x4):" << endl;
    printMatrix(result4);
    cout << "Matches naive? " << (matricesEqual(result4, naiveMultiply(A4, B4)) ? "yes" : "no") << endl << endl;

    // test 3: random 8x8 matrices
    int n = 8;
    Matrix Arand = randomMatrix(n);
    Matrix Brand = randomMatrix(n);
    Matrix resultRand = strassenMultiply(Arand, Brand);
    cout << "Test 3 (random 8x8): Matches naive? "
         << (matricesEqual(resultRand, naiveMultiply(Arand, Brand)) ? "yes" : "no") << endl;

    return 0;
}