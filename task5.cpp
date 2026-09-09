#include <iostream>
#include <vector>
using namespace std;
// this will generates Pascals triangle with n rows
vector<vector<int>> generatePascalsTriangle(int n) {
    vector<vector<int>> triangle;
 for (int row = 0; row < n; row++) {
        vector<int> currentRow(row + 1);
        currentRow[0] = 1;
        currentRow[row] = 1;
 // this code snippet will iterate for each inner value = sum of the two values above it
        for (int col = 1; col < row; col++) {
            currentRow[col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
        }

        triangle.push_back(currentRow);
    }

    return triangle;
}

void printTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main() {
    // Test 1  n = 0 no rows
    cout << "Test 1 n = 0:" << endl;
    printTriangle(generatePascalsTriangle(0));
    cout << "Expected: (nothing printed)" << endl << endl;
// Test 2 n = 1 single row
    cout << "Test 2 n = 1:" << endl;
    printTriangle(generatePascalsTriangle(1));
    cout << "Expected: 1" << endl << endl;
// Test 3 n = 5 this will verify the row provide
    cout << "Test 3 n = 5:" << endl;
    printTriangle(generatePascalsTriangle(5));
    cout << "Row 5 should be: 1 4 6 4 1" << endl;
    return 0;
}