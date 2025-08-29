#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> pos;
    int maxlen = 0, start = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (pos.count(s[i]) && pos[s[i]] >= start) start = pos[s[i]] + 1;
        pos[s[i]] = i;
        maxlen = max(maxlen, i - start + 1);
    }
    return maxlen;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
}
