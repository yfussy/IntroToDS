#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(NULL);
    int q, version = 1;
    map<int, map<int, int>> git; // pos : {version}
    cin >> q;
    while (q) {
        char op;
        int pos, v;
        cin >> op >> pos >> v;
        if (op == 'U') {
            if (!git.count(pos)) git[pos][0] = -1;
            git[pos][version++] = v;
        } else {
            if (!git.count(pos)) {
                cout << -1 << endl;
            }
            else {
                if (git[pos].count(v)) {
                    cout << git[pos][v] << endl;
                } else {
                    auto it = git[pos].lower_bound(v);
                    --it;
                    cout << it->second << endl;
                }

            }
        }
        --q;
    }
}   
