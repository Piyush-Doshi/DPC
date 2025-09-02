#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int eval(string s) {
    stack<int> st;
    istringstream iss(s);
    string token;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else st.push(a / b);
        } else {
            st.push(stoi(token));
        }
    }
    return st.top();
}

int main() {
    string s = "2 1 + 3 *";
    cout << eval(s) << endl;
    return 0;
}
