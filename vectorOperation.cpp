#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    cin.ignore();
    vector<int> v;
    for (int i = 0; i < q; i++) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        string op;
        iss >> op;
        if (op == "pb") {
            int x;
            iss >> x;
            v.push_back(x);
        } else if (op == "sa") {
            sort(v.begin(), v.end());
        } else if (op == "sd") {
            sort(v.begin(), v.end(), greater<int>());
        } else if (op == "r") {
            reverse(v.begin(), v.end());
        } else if (op == "d") {
            int i;
            iss >> i;
            v.erase(v.begin() + i);
        }
    }

    for (auto &x : v) {
        cout << x << " ";
    }
}