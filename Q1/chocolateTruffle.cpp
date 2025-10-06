#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long r, c, n, p, q;
    vector<long long> fav;
    cin >> r >> c >> n;
    for (long long i = 0; i < n; i++) {
        cin >> p >> q;
        fav.push_back((long long)(p - 1) * c + q);
    }
    sort(fav.begin(), fav.end());
    fav.push_back(fav[0] + (long long)(r*c));

    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> p >> q;
        long long start = (long long)(p - 1) * c + q;
        auto end_it = lower_bound(fav.begin(), fav.end(), start);
        cout << *end_it - start << endl;
    }
}