#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, start, end;
    cin >> n;

    set<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        cin >> start >> end;

        auto it = q.lower_bound({start, 0});

        if (it != q.begin()) {
            auto prev_it = prev(it);
            if (prev_it->second >= start) {
                continue;
            }
        }

        if (it != q.end() && it->first <= end) {
            continue;
        }

        q.insert({start, end});
        cout << i << " ";
    }
}