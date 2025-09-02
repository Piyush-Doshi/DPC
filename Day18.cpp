#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 1; i <= sqrt(N); ++i) {
        if (N % i == 0) {
            if (N / i == i)
                count++;
            else
                count += 2;
        }
    }
    cout << count;
    return 0;
}
