#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    map<string, int> m;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        m[s]++;
    }

    vector<pair<string, int>> v;
    for (auto &x : m) {
        v.push_back(x);
    }

    sort(v.begin(), v.end(), 
        [](auto &L, auto &R) { 
            if (L.second != R.second) { return L.second < R.second; }
            return L.first < R.first; 
        }
    );

    auto it = v.end() - 1;
    cout << it->first << " " << it->second;
}