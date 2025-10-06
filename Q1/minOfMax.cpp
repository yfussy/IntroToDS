#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m, t;
    cin >> n >> m;
    vector<int> typeCollection(m, 1);
    vector<int> pw(n);
    multiset<int> teampPw;
    for (int i = 0; i < n; i++) cin >> pw[i];
    for (int i = 0; i < m; i++) teampPw.insert(1);
    for (int i = 0; i < n; i++) {
        cin >> t;
        teampPw.erase(teampPw.find(typeCollection[t]));
        typeCollection[t] = max(typeCollection[t], pw[i]);
        teampPw.insert(typeCollection[t]);
        cout << *teampPw.begin() << " ";
    }
}