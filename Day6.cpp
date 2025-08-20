#include <iostream.h>
#include <vector>
using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(const vector<int>& arr) {
    vector<pair<int, int>> result;
    int n = arr.size();
    for (int start = 0; start < n; ++start) {
        int sum = 0;
        for (int end = start; end < n; ++end) {
            sum += arr[end];
            if (sum == 0)
                result.push_back({start, end});
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<pair<int, int>> subarrays = findZeroSumSubarrays(arr);

    if (subarrays.empty()) {
        cout << "No zero-sum subarrays found.\n";
    } else {
        cout << "Zero-sum subarrays (start, end indices):\n";
        for (auto &p : subarrays)
            cout << "(" << p.first << ", " << p.second << ")\n";
    }
    return 0;
}
