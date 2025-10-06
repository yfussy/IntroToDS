#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n, num;
    cin >> n;
    
    queue<int> in;
    vector<int> order;
    unordered_map<int, int> seen;
    for (int i = 0; i < n; i++) {
        cin >> num;
        in.push(num);
        order.push_back(num);
    }

    sort(order.begin(), order.end());

    while(!in.empty()) {
        num = in.front();
        in.pop();
        seen[num]++;
        cout << lower_bound(order.begin(), order.end(), num) - order.begin() + seen[num] << " ";
    }

}