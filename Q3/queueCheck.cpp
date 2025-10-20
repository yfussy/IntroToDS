#include <iostream>

using namespace std;

int main() {
    int mFront, mCap, mSize, last, correction, n;
    cin >> n;
    while (n--) {
        cin >> mFront >> mSize >> mCap >> last >> correction;
        
        if (mCap <= mFront || mCap < mSize || mCap <= last || (mFront + mSize) % mCap != last) {
            cout << "WRONG";

            switch (correction) {
                case 0:
                    cout << endl;
                    break;
                case 1:
                    mFront = (last - mSize) % mCap;
                    if (mFront < 0) mFront += mCap;
                    cout << " " << mFront << endl;
                    break;
                case 2:
                    mSize = (last - mFront) % mCap;
                    if (mSize < 0) mSize += mCap;
                    cout << " " << mSize << endl;
                    break;
                case 3: {
                    mCap = mFront < last ? last + 1 : mFront + mSize - last;
                    cout << " " << mCap << endl;
                    break;
                }
                case 4:
                    cout << " " << (mFront + mSize) % mCap << endl;
                    break;
                }
                
            continue;
        }

        cout << "OK" << endl;
    }
}