#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m, size;
    cin >> n >> m;
    set<int> shoes;

    for (int i = 0; i < n; i++) {
        cin >> size; 
        shoes.insert(size);
    }

    for (int i = 0; i < m; i++) {
        cin >> size;
        auto it = shoes.lower_bound(size);
        if (it == shoes.begin() || it == shoes.end()) {
            it = it == shoes.begin() ? it : prev(it);
            cout << *it << " ";
            continue;
        }
        int diff = abs(*it - size);
        auto it_prev = prev(it);
        it = diff <= abs(*it_prev - size) ? it : it_prev;
        cout << *it << " ";
    }
}