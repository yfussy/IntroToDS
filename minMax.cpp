#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, r, num;
    cin >> n >> m >> r;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int r1, r2, c1, c2;
    for (int i = 0; i < r; i++) {
        cin >> r1 >> r2 >> c1 >> c2;
        if (r1 > c1 || r2 > c2) {
            cout << "INVALID" << endl;
        } else if ((r1 < 0 || r2 < 0 || r1 > n || r2 > m) 
                && (c1 < 0 || c2 < 0 || c1 > n || c2 > m)) {
            cout << "OUTSIDE" << endl;
        } else {
            r1 = r1 < 0 ? 0 : std::min(r1, n) - 1;
            r2 = r2 < 0 ? 0 : std::min(r2, m) - 1;
            c1 = c1 < 0 ? 0 : std::min(c1, n);
            c2 = c2 < 0 ? 0 : std::min(c2, m);
            int max = matrix[r1][r2];
            for (int i = r1; i < c1; i++) {
                for (int j = r2; j < c2; j++) {
                    max = std::max(matrix[i][j], max);
                }
            }
            cout << max << endl;
        }
    }
}