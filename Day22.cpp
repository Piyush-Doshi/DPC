#include <bits/stdc++.h>
using namespace std;

int firstElement(int arr[], int n, int k) {
    unordered_map<int, int> count_map;
    for (int i = 0; i < n; ++i)
        count_map[arr[i]]++;
    for (int i = 0; i < n; ++i)
        if (count_map[arr[i]] == k)
            return arr[i];
    return -1;
}

int main() {
    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << firstElement(arr, n, k);
    return 0;
}
