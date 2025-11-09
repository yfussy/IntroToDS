#include <iostream>
#include <list>

using namespace std;

int main() {
    int n, pos, col;

    cin >> n >> pos >> col;
    list<int> zuma;
    for (size_t i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (i == pos) {
            zuma.push_back(col);
        }
        zuma.push_back(tmp);
    }

    auto lp = next(zuma.begin(), pos);
    auto rp = next(zuma.begin(), pos);
    while (!zuma.empty()) {
        while (*lp == *prev(lp)) {
            lp = prev(lp);
        }

        while (*rp == *next(rp)) {
            rp = next(rp);
        }

        if (distance(lp, rp) + 1 < 3) break;

        lp = prev(zuma.erase(lp, next(rp)));
        rp = lp;

    }

    for (auto it = zuma.begin(); it != zuma.end(); ++it) cout << *it << " ";
}