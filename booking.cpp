#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m, k;
    cin >> n >> m;

    string t1, t2;
    unordered_map<string, unordered_set<string>> t;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        t[t1].insert(t2);
    }

    for (int i = 0; i < m; i++) {
        vector<pair<string, string>> checking, request;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> t1 >> t2;
            request.push_back({t1, t2});
        }
        
        bool valid = true;
        for (auto &r : request) {
            t1 = r.first, t2 =r.second;
            if (!t[t1].count(t2)) {
                for (auto &tk : checking) {
                    t[tk.first].insert(tk.second);
                }
                valid = false;
                cout << "NO\n";
                break;
            }
            checking.push_back(r);
            t[t1].erase(t2);
        }
        
        if (valid) cout << "YES\n";
    }
}