#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    map<int, int> ranges;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ranges[a] = b;
    }

    for (int i = 0; i < m; i++) {
        cin >> a;
        auto it = ranges.upper_bound(a) == ranges.begin() ? ranges.begin() : prev(ranges.upper_bound(a));
        if (a >= it->first && a <= it->second) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
}