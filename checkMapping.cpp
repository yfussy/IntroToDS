#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, d;
    cin >> n;
    set<int> seen;
    for (int i = 0; i < n; i++) {
        cin >> d;
        if (d < 1 || d > n || seen.count(d)) {
            cout << "NO";
            return 0;
        }
        seen.insert(d);
    }
    cout << "YES";
}