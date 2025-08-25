#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void permute(string &s, int l, vector<string> &res) {
    if (l == s.size() - 1) {
        res.push_back(s);
        return;
    }
    for (int i = l; i < s.size(); ++i) {
        if (i != l && s[i] == s[l]) continue;
        swap(s[l], s[i]);
        permute(s, l + 1, res);
        swap(s[l], s[i]);
    }
}

vector<string> uniquePermutations(string s) {
    sort(s.begin(), s.end());
    vector<string> res;
    permute(s, 0, res);
    return res;
}

int main() {
    string s = "abc";
    vector<string> result = uniquePermutations(s);
    for (auto &perm : result) {
        cout << perm << endl;
    }
    return 0;
}
