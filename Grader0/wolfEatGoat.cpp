#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    long long p;
    cin >> n;

    set<long long> pos;
    for (int i = 0; i < n; i++) {
        cin >> p;
        pos.insert(p);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        auto it = pos.lower_bound(p);
        long long forward = abs(*it - p);
        if (it == pos.begin()) { cout << forward << endl; continue; }
        long long backward = abs(p - *prev(it));
        cout << min(forward, backward) << endl;
    }

}