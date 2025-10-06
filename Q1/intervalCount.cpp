#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k, p;
    cin >> n >> m >> k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> p;
        v.push_back(p);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        cin >> p;
        int begin = p - k;
        int end = p + k;
        auto it_begin = lower_bound(v.begin(), v.end(), begin);
        auto it_end = upper_bound(v.begin(), v.end(), end);
        cout << it_end - it_begin << " ";
    }

}