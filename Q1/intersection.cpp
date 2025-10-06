#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, num;
    cin >> n >> m;
    vector<int> a(n), intersect;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < m; i++) {
        cin >> num;
        auto it = lower_bound(a.begin(), a.end(), num);
        if (*it == num) {
            if (intersect.size() == 0) {
                intersect.push_back(num);
                continue;
            }
            it = lower_bound(intersect.begin(), intersect.end(), num);
            if (*it != num) {
                intersect.insert(it, num);
            }
        }
    }

    for (auto &x : intersect) { cout << x << " "; }
}
