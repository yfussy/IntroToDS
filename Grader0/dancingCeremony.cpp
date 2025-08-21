#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long perfect = 0;
    long long d;
    cin >> n;

    vector<long long> sum(n);
    for (int i = 0; i < n; i++) {
        cin >> sum[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> d;
        sum[i] -= d;
    }

    sort(sum.begin(), sum.end());

    for (int i = 0; i < sum.size(); i++) {
        long long selected = sum[i];
        auto it = upper_bound(sum.begin() + i + 1, sum.end(), -selected);
        perfect += sum.end() - it;
    }

    cout << perfect;
}