#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    istringstream iss(s);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    reverse(words.begin(), words.end());

    string result;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i) result += " ";
        result += words[i];
    }

    return result;
}

int main() {
    string s = "the sky is blue";
    cout << "\"" << reverseWords(s) << "\"" << endl;
    return 0;
}
