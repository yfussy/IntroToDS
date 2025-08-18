#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m;
    unordered_set<int> seen;
    vector<int> intersect;

    for (int i = 0; i < n; i++) {
        cin >> c;    
        seen.insert(c);
    }

    for (int i = 0; i < m; i++) {
        cin >> c;
        if (seen.count(c)) {
            intersect.push_back(c);
        }
    }

    sort(intersect.begin(), intersect.end());
    intersect.erase(unique(intersect.begin(), intersect.end()), intersect.end());
    for (auto &x : intersect) { cout << x << " "; }
    cout << endl;
}