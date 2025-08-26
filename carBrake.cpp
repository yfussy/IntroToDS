#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k, t, d, a, q;
    cin >> n >> m >> k;

    set<pair<int, int>> ts;
    for (int i = 0; i < n; i++) {
        cin >> t >> d;
        ts.insert({t, d});
    }

    map<int, int> speedLog;
    int s = k;
    speedLog[0] = s;
    for (auto &t : ts) {
        s -= t.second;
        speedLog[t.first] = max(0, s);
    }

    vector<int> time, speed;
    for (auto it = speedLog.rbegin(); it != speedLog.rend(); it++) {
        time.push_back(it->first);
        speed.push_back(it->second);
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> q;
        if (a == 1) {
            auto it = speedLog.lower_bound(q);
            it = it->first == q ? it : prev(it);
            cout << it->second << endl;
        } else {
            if (q > k) {
                cout << 0 << endl;
                continue;
            }

            auto it_speed = lower_bound(speed.begin(), speed.end(), q);
            int interval = it_speed == speed.begin() ? time[0] : time[prev(it_speed) - speed.begin()];
            cout << interval << endl;
        }
    }
}