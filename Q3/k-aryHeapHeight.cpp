#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    if (k == 1) cout << n - k;
    else cout << ceil(log(n * (k - 1) + 1) / log(k)) - 1;
}