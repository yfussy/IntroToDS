#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m, a;
    cin >> n >> m >> a;
    vector<int> stock(n);
    map<int, set<pair<int, int>>> bid;
    map<int, map<int, int>> bidLog;
    map<int, vector<int>> user;
    for (int i = 0; i < n; ++i) {
        cin >> stock[i];
    }

    char op;
    for (int i = 0; i < a; ++i) {
        cin >> op;
        int u, id, v;
        switch (op) {
        case 'B':
            cin >> u >> id >> v;
            if (bidLog[id].count(u)) bid[id].erase({bidLog[id][u], u});
            bid[id].insert({v, u});
            bidLog[id][u] = v;
            break;
        
        case 'W':
            cin >> u >> id;
            v = bidLog[id][u];
            bid[id].erase({v, u});
            break;
        }
    }

    for (auto &[id, b] : bid) {
        while (stock[id-1]-- && b.size()) {
            user[prev(b.end())->second].push_back(id);
            b.erase(prev(b.end()));
        } 
    }

    for (int i = 1; i <= m; i++) {
        if (user.find(i) == user.end()) {
            cout << "NONE" << endl;
            continue;
        }

        for (auto &item : user[i]) cout << item << " ";
        cout << endl;
    }
}