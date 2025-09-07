#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m, start, s, a, x, p;
    cin >> n >> m >> start;

    const int MAX = 1e5 + 1;

    vector<pair<int, int>> changes;
    changes.push_back({0, start});
    changes.push_back({MAX, 0});
    for (int i = 0; i < n; i++) {
        cin >> a >> s;
        changes.push_back({a, s});
    }
    sort(changes.begin(), changes.end());

    int money[MAX];
    int day = 1;
    money[0] = start;
    for (size_t i = 0; i < n + 1; i++) {
        while (day < changes[i+1].first) {
            money[day] = money[day - 1] + changes[i].second;
            day++;
        }
    }

    while (m--) {
        cin >> p >> x;
        if (money[x] >= p) cout << lower_bound(money, money + MAX, p) - money<< " ";
        else cout << lower_bound(money, money + MAX, p + money[x]) - money<< " ";
    }
}