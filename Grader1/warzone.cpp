#include <iostream>
#include <set>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> warzone;
    int start, end, casualties;
    while (m--) {
        cin >> start >> end;

        auto it = warzone.lower_bound({start, end});
        if (it != warzone.begin()) {
            auto prev_it = prev(it);
            if (prev_it->second >= start) it = prev_it;
        }

        int overlapped = 0;
        while (it != warzone.end() && it->first <= end) {
            overlapped += it->second - it->first + 1;
            start = min(start, it->first);
            end = max(end, it->second);
            it = warzone.erase(it);
        }

        warzone.insert({start, end});
        casualties = end - start + 1;
        n -= casualties - overlapped;
        cout << n << endl;
    }
}