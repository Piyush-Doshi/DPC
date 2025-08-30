//LCM

#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main() {
    long long N, M;
    cin >> N >> M;
    cout << N * M / gcd(N, M) << endl;
    return 0;
}
