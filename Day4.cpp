#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();
    
    int i = 0, j = 0, k = m - 1;

    // Swap until arr1 is smaller and arr2 contains larger elements
    while (i <= k && j < n) {
        if (arr1[i] <= arr2[j]) {
            i++;
        } else {
            swap(arr1[k], arr2[j]);
            k--;
            j++;
        }
    }

    // Sort both arrays again
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    mergeArrays(arr1, arr2);

    cout << "arr1: ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2: ";
    for (int x : arr2) cout << x << " ";
    return 0;
}
