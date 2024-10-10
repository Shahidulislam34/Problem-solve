#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for gcd

using namespace std;

// Function to find the smallest GCD among all pairs in the array
int findSmallestPairGCD(vector<int>& arr) {
    // Sort the array to make it easier to find the smallest GCD between adjacent numbers
    sort(arr.begin(), arr.end());

    // Initialize minGCD with a large value
    int minGCD = numeric_limits<int>::max();

    // Find the GCD of adjacent elements in the sorted array
    for (size_t i = 1; i < arr.size(); ++i) {
        int gcdValue = gcd(arr[i], arr[i - 1]);
        minGCD = min(minGCD, gcdValue);
    }

    return minGCD;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = findSmallestPairGCD(arr);
    cout << "The smallest possible GCD of any pair in the array is: " << result << endl;

    return 0;
}
