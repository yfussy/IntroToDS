#include <iostream>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        if (a == b) {
            cout << "a and b are the same node" << endl;
            continue;
        }

        int ancestor = a, descendant = b;
        if (a > b) swap(ancestor, descendant);
        bool isAncestor = false;
        int cur = descendant;
        while (cur > 0) {
            cur = (cur - 1) / 2;
            if (cur == ancestor) {
                isAncestor = true;
                break;
            }
        }

        if (isAncestor) {
            if (a < b) cout << "a is an ancestor of b" << endl;
            else cout << "b is an ancestor of a" << endl;
        } else {
            cout << "a and b are not related" << endl;
        }
    }
    
}