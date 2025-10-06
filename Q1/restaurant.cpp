#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m;
    vector<int> time;
    for (int i = 0; i < n; i++) {
        cin >> t;
        time.push_back(t);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> seats;
    for (auto &chef : time) {
        seats.push({0, chef});
    }

    for (int i = 0; i < m; i++) {
        auto [t, chef] = seats.top();
        seats.pop();

        cout << t << endl;

        seats.push({t+chef, chef});
    }
}