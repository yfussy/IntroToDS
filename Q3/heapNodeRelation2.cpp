#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int relation(long long S, long long a, long long b) {
    
    long long ancestor = a, descendant = b;
    if (a > b) swap(ancestor, descendant);

    if ((descendant - 1) / S == ancestor) return 1;

    long long cur = descendant;
    while (cur > 0) {
        cur = (cur - 1) / S;
        if (cur == ancestor) {
            return 2;
        }
    }

    long long aH = floor(log(a * (S - 1) + 1) / log(S));
    long long bH = floor(log(b * (S - 1) + 1) / log(S));
    
    if (aH == bH) return 4;
    return 3;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    long long S,a,b;
    
    cin >> n;
    while (n--) {
        cin >> S >> a >> b;
        cout << relation(S,a,b) << " ";
    }
    cout << endl;
}