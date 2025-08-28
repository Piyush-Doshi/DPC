#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countAtMostK(string& s, int k) {
    vector<int> freq(26, 0);
    int n = s.length();
    int left = 0, ans = 0, distinct = 0;
    for (int right = 0; right < n; ++right) {
        if (freq[s[right] - 'a'] == 0)
            distinct++;
        freq[s[right] - 'a']++;
        while (distinct > k) {
            freq[s[left] - 'a']--;
            if (freq[s[left] - 'a'] == 0)
                distinct--;
            left++;
        }
        ans += right - left + 1;
    }
    return ans;
}

int substrCount(string& s, int k) {
    return countAtMostK(s, k) - countAtMostK(s, k-1);
}

int main() {
    string s = "pqpqs";
    int k = 2;
    cout << substrCount(s, k) << endl;
    return 0;
}
