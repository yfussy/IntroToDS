#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool pairSum(vector<int> &v, int target) {
    int mid;
    for (int i = 0; i < v.size() - 1; i++) {
        int comp = target - v[i];
        int left = i + 1;
        int right = v.size() - 1;
        while (left <= right) {
            mid = left + (right - left)/2;
            if (v[mid] == comp) {
                return true;
            } else if (v[mid] < comp) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    int n, m, c;
    vector<int> v;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        cin >> c;
        cout << (pairSum(v, c) ? "YES\n" : "NO\n"); 
    }
}