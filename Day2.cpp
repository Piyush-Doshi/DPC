/*
You are given an array arr containing n-1 distinct integers. The array consists of integers taken from the range 1 to n, meaning one integer is missing from this sequence. Your task is to find the missing integer.
*/

#include <iostream>
#include <vector>
using namespace std;

int missingNo(const vector<int>& arr, int n) {
    long long sum1 = 1LL * n * (n + 1) / 2;
    long long sum2 = 0;

    for (int num : arr) {
        sum2 += num;
    }
    return (int)(sum1 - sum2);
}
int main() {
    int n;
    cout << "Enter the value of n (range is 1 to n): ";
    cin >> n;

    vector<int> arr(n - 1);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    cout << "Missing number: " << missingNo(arr, n) << endl;
    return 0;
}
