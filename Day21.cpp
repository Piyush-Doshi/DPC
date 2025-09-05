#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
    } else {
        int temp = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(temp);
    }
}

void reverse(stack<int>& st) {
    if (!st.empty()) {
        int temp = st.top();
        st.pop();
        reverse(st);
        insertAtBottom(st, temp);
    }
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    stack<int> temp = st;
    cout << "Original Stack" << endl;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverse(st);

    cout << "Reversed Stack" << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
