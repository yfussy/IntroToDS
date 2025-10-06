#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int spaces = pow(2, ceil(log2(n)));
    cout << spaces - n;
}