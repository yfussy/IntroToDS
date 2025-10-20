#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, a;
    long long k, mCap = 1, mSize = 0;
    cin >> n;
    while (n--) {
        cin >> a >> k;
        if (!a) {
            mSize += k;
            if (mSize > mCap) {
                long long a = log2(mSize);
                if (pow(2, a) == mSize) mCap = mSize;
                else mCap = pow(2, a + 1);
            }
        } else {
            mSize -= k;
        }
    }

    cout << mCap - mSize;
}