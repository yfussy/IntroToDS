#include <iostream>
#include <map>
#include <vector>

using namespace std;

long long findGrandFather(map<long long, long long> &m, long long son) {
    for (int i = 0; i < 2; i++) {
        auto father = m.find(son);
        if (father == m.end()) {
            return 0;
        }
        son = father->second;
    }
    return son;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int n, m;
    long long father, son, a, b, grandfatherA, grandfatherB;
    map<long long, long long> parent;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> father >> son;
        parent[son] = father;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a == b) {
            cout << "NO" << endl;
            continue;
        }

        grandfatherA = findGrandFather(parent, a);
        grandfatherB = findGrandFather(parent, b);
        if (grandfatherA == grandfatherB && grandfatherA != 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}