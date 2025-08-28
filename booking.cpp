#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

bool canBook(unordered_map<string, unordered_set<string>> &t, queue<pair<string, string>> q) {
    for (int i = 0; i < q.size(); i++) {
        string t1 = q.front().first, t2 = q.front().second;
        if (!t[t1].count(t2)){
            return false;
        }
        q.pop();
    }
    return true;
}

int main() {
    int n, m, k;
    cin >> n >> m;

    string t1, t2;
    unordered_map<string, unordered_set<string>> t;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        t[t1].insert(t2);
    }

    queue<pair<string, string>> q;
    for (int i = 0; i < m; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> t1 >> t2;
            q.push({t1, t2});
        }
        if (canBook(t, q)) {

        } else {
            continue;
        }
    }
}