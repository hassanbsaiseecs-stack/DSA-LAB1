#include <iostream>
#include <vector>
using namespace std;

//this finds the most frequent element in the array
int findMode(vector<int> arr) {
    int mode = arr[0];
    int maxCount = 0;

    // for every element it will count how many times it appears
    for (int i = 0; i < arr.size(); i++) {
        int count = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        // if this element appears more than our current best it will get update
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }

    return mode;
}

int main() {
    // test case 1: array with a unique mode
    vector<int> arr1 = {1, 2, 2, 3, 2, 4};
    cout << "Test 1 unique mode: " << findMode(arr1) << "  Expected: 2" << endl;

    // test case 2: array with multiple modes tie between 1 and 2
    vector<int> arr2 = {1, 1, 2, 2, 3};
    cout << "Test 2 multiple modes: " << findMode(arr2) << "  Expected: 1 first one found" << endl;

    // test case 3: empty array
    vector<int> arr3 = {};
    if (arr3.empty()) {
        cout << "Test 3 empty array: no mode, array is empty" << endl;
    } else {
        cout << "Test 3 empty array: " << findMode(arr3) << endl;
    }

    return 0;
}