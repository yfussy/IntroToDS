#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); 

    int m;
    cin >> m;
    while (m--) {
        int n, k;
        cin >> n >> k;

        int *mData = new int[n];
        cin >> mData[0];

        int tmp;
        bool skip = false;
        for (int i = 1; i < n; ++i) {
            cin >> tmp;
            size_t p = (i - 1) / k;
            if (tmp >= mData[p] && !skip) {
                cout << "false\n";
                skip = true;
            } 
            mData[i] = tmp;
        }

        if (!skip) cout << "true\n";

        delete[] mData;
    }
}