#include <iostream>
#include <vector>
using namespace std;

// this returns all indices in arr where key occurs
vector<int> findAllIndices(const vector<int>& arr, int key) {
    vector<int> indices;
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }
    return indices;
}

void printVector(const vector<int>& v) {
    cout << "{ ";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << " }";
}

int main() {
    // the first  testcase to check for multiple occurrences of the key
    vector<int> arr1 = {2, 5, 8, 5, 1, 5, 9};
    cout << "Test 1 multiple occurrences: ";
    printVector(findAllIndices(arr1, 5));
    cout << "  Expected:  1, 3, 5 " << endl;

    // 2nd test case to  check key does not exist in the array
    vector<int> arr2 = {10, 20, 30, 40};
    cout << "Test 2 key not present: ";
    printVector(findAllIndices(arr2, 99));
    cout << "  Expected:   " << endl;

    // Third test case 
    vector<int> arr3 = {};
    cout << "Test 3 empty array: ";
    printVector(findAllIndices(arr3, 7));
    cout << "  Expected: " << endl;

    return 0;
}