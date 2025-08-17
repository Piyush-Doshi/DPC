/*
Find the Duplicate Number, and it requires O(n) time, O(1) space, and cannot modify the input array.
*/
#include <iostream>
#include <vector>
using namespace std;

int duplicate(vector<int>& arr) {
    int slow = arr[0], fast = arr;
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr;
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    vector<int> arr(n + 1);
    cout << "Enter " << n + 1 << " numbers (range 1 to " << n << "):\n";
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    int ans = duplicate(arr);
    cout << "Duplicate number: " << ans << endl;

    return 0;
}
