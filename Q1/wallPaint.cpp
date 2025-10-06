#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    int n, m, x, c, d;
    cin >> n >> m;

    int layer = 0;
    vector<int> wall(n);
    map<int, pair<int, int>> order;
    for (int i = 0; i < 2 * m; i++) {
        cin >> x >> c >> d;
        if (!d) {
            order[c].first = x;
        } else {
            order[c].second = x;
        }
    }

    for (auto &o : order) {
        auto &[start, end] = o;
         
    }
}