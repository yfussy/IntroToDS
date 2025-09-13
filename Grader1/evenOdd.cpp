#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int q, x;
    cin >> q;
    int even = 0, odd = 0;
    unordered_set<int> evenOdd, seen;
    
    for (int i = 0; i < q; i++) {
        cin >> x;
        if (evenOdd.count(x)) {
            even++;
            odd = max(0, odd - 1);
            evenOdd.erase(x);
        } else {
            odd++;
            if (seen.count(x)) even--;
            evenOdd.insert(x);
        }
        seen.insert(x);
        cout << even << " " << odd << endl;
    }
}