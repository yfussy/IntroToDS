#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// implementation of `Most Frequent Word` problem
int main() {
    int n, k;
    string s;
    map<string, int> m;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s;
        m[s]++;
    }
    vector<pair<string, int>> v;
    for (auto &x : m) {
        v.push_back(x);
    }

    sort(v.begin(), v.end(), [](auto &L, auto &R) { return L.second < R.second; });

    if (v.size() < k) {
        cout << v.begin()->second;
    } else {
        cout << (v.end() - k)->second;
    }
}