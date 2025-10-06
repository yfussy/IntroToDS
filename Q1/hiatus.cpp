#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;

    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        s.insert({a, b});
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        pair<int, int> date = {a, b};
        if (s.count(date)) {
            cout << 0 << " " << 0 << " ";
            continue;
        }

        auto it = s.lower_bound(date);
        it = it == s.begin() ? it : prev(it);
        if (date < *it) {
            cout << -1 << " " << -1 << " ";
            continue;
        }

        cout << it->first << " " << it->second << " ";
    }
}