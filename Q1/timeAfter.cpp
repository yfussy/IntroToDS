#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int h, m, x;
    cin >> h >> m >> x;
    int total = (h * 60) + m + x;
    h = (total / 60) % 24;
    m = total % 60;
    cout << setfill('0') << setw(2) << h << " " << setfill('0') << setw(2) << m;
}