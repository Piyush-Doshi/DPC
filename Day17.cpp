#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primeFactors(int n) {
    vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i*i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
    return factors;
}

int main() {
    int n = 18;
    vector<int> factors = primeFactors(n);
    for (int f : factors)
        cout << f << " ";
    cout << endl;
    return 0;
}
