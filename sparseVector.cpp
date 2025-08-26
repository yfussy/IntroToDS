#include <iostream>
#include <vector>
#include <map>

using namespace std;

void insert_into_sv(map<int,int> &v, int pos, int value) {
    vector<pair<int, int>> kv;
    auto it = v.lower_bound(pos);
    for (auto it_shift = it; it_shift != v.end(); it_shift = next(it_shift)) {
        kv.push_back({it_shift->first + 1, it_shift->second});
    }

    it = v.erase(it, v.end());
    it = v.insert(it, {pos, value});
    for (size_t i = 0; i < kv.size(); i++) {
        it = v.insert(it, kv[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    map<int,int> v;

    cin >> n;
    for (int i = 0;i < n;i++) {
        int a,b;
        cin >> a >> b;
        insert_into_sv(v,a,b);
    }

    cout << v.size() << "\n";
    for (auto &x : v) {
        cout << x.first << ": " << x.second << "\n";
    }
}