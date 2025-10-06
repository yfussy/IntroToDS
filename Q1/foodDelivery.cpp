#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m, num, op, a, b;
    cin >> n >> m;

    vector<int> target;
    for (int i = 0; i < m; i++) {
        cin >> num;
        target.push_back(num);
    }

    queue<int> platong, dotman;
    vector<int> result, sales;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            if (a == 1) {
                platong.push(b);
            } else {
                dotman.push(b);
            }
        } else {
            // taking order
            int check;
            if (!platong.empty()) {
                check = platong.front();
                if (!dotman.empty() && dotman.front() < check) {
                    check = dotman.front();
                    dotman.pop();
                } else {
                    platong.pop();
                }
            } else {
                check = dotman.front();
                dotman.pop();
            }

            // pushing sales log
            if (!sales.empty()) {
                sales.push_back(sales.back() + check);
            } else {
                sales.push_back(check);
            }
        }
    }

    for (int &t : target) {
        if (sales.empty() || t > sales.back()) {
            cout << -1 << " "; continue;
        }
        auto it = lower_bound(sales.begin(), sales.end(), t);
        cout << it - sales.begin() + 1 << " ";
    }
}