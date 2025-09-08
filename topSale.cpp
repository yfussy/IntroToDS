#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m, code, op;
    cin >> n >> m;

    map<int, int> codeSales;
    map<int, set<int>> salesCode;
    for (int i = 0; i < n; i++) {
        cin >> code;
        codeSales[code];
    }

    while (m--) {
        cin >> op;

        int amount;
        switch (op)
        {
            case 1: {
                cin >> code >> amount;
                if (!codeSales.count(code)) break;
                int curretSales = codeSales[code];
                int totalSales = curretSales + amount;
                if (salesCode.count(curretSales)) {
                    salesCode[curretSales].erase(code);
                    if (salesCode[curretSales].empty()) salesCode.erase(curretSales);
                }
                salesCode[totalSales].insert(code);
                codeSales[code] = totalSales;
                break;
            }
            case 2: {
                cin >> amount;
                auto it = salesCode.lower_bound(amount);
                if (it == salesCode.begin()) {
                    cout << "NONE" << endl; 
                    break;
                }
                cout << *prev(prev(it)->second.end()) << endl;
                break;
            }
        }
    }
}