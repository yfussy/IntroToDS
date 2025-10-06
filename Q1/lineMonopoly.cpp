#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    const char nl = '\n';
    const int MAX = 1e9;

    auto compareFirst = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.first < rhs.first;
    };

    int n, op;
    cin >> n;
    set<pair<int, int>, decltype(compareFirst)> monopoly(compareFirst);
    while (n--) {
        cin >> op;
        switch (op) {
            case 1: {
                int start, end;
                cin >> start >> end;
                auto it = monopoly.lower_bound({start, end});

                if (it != monopoly.begin()) {
                    auto prev_it = prev(it);
                    if (prev_it->second >= start - 1) it = prev_it;
                }

                while (it != monopoly.end() && it->first <= end + 1) {
                    start = min(start, it->first);
                    end = max(end, it->second);
                    it = monopoly.erase(it);
                }

                monopoly.insert({start, end});
                break;
            }
            case 2: {
                cout << monopoly.size() << endl;
                break;
            }
        }
    }
}