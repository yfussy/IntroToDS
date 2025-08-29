#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, w, num;
    cin >> n >> w;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }

    int windowSize = w + 1;
    multiset<int> window;
    vector<int> result;
    for (int i = 0; i < windowSize; i++) {
        window.insert(v[i]);
    }

    result.push_back(*next(window.begin(), windowSize/2));

    for(int i = windowSize; i < n; i++) {
        window.erase(window.find(v[i-windowSize]));
        window.insert(v[i]);
        result.push_back(*next(window.begin(), windowSize/2));
    }

    for (auto &x : result) cout << x << " ";
}