#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void member_multiply(vector<int> &v, vector<pair<vector<int>::iterator,int>> &multiply) {
    vector<pair<int, int>> idxes;
    for (auto &m : multiply) idxes.push_back({m.first - v.begin(), m.second});
    
    sort(idxes.begin(), idxes.end(), [](auto &L, auto &R) {
        return R < L;
    });

    for (auto &i : idxes) {
        v.insert(v.begin() + i.first, i.second, v[i.first]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<vector<int>::iterator,int>> multiply(m);
    for (int i = 0;i < n;i++) cin >> v[i];
    for (int i = 0;i < m;i++) {
        int a,b;
        cin >> a >> b;
        multiply[i].first = v.begin()+a;
        multiply[i].second = b;
    }

    member_multiply(v,multiply);
    
    cout << "======= result ========" << endl;
    cout << v.size() << endl;
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}