#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m, c;
    cin >> n >> m;
    multiset<int> deck;
    for (int i = 0; i < n; i++) {
        cin >> c;
        deck.insert(c);
    }

    bool lose = false;
    int rounds = 1;
    for (int i = 0; i < m; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> c;
            auto it = deck.upper_bound(c);
            if (it == deck.end()) {
                lose = true;
                break;
            }
            deck.erase(it);
        }
        if (lose) break;
        rounds++;
    }
    cout << rounds;
}