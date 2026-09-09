#include <iostream>
#include <string>
using namespace std;
//this will  returns the index of the first occurrence of pattern in text or -1 if not found
int naiveSearch(const string& text, const string& pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();

    if (m == 0) return 0; // this will check if the empty pattern matches at the start

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}
int main() {
    // Test 1 to check pattern at the beginning
    cout << "Test 1 pattern at beginning: "
         << naiveSearch("hello world", "hello")
         << "  Expected: 0" << endl;
// Test 2 to check pattern at the end
    cout << "Test 2 pattern at end: "
         << naiveSearch("hello world", "world")
         << "  Expected: 6" << endl;
 // Test 3 to check pattern not present
    cout << "Test 3 pattern not present: "
         << naiveSearch("hello world", "xyz")
         << "  Expected: -1" << endl;
// Test 4 to check empty pattern
    cout << "Test 4 empty pattern: "
         << naiveSearch("hello world", "")
         << "  Expected: 0" << endl;

    return 0;
}