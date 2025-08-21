#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    string word;
    cin >> n;

    map<string, int> hist;
    for (int i = 0; i < n; i++) {
        cin >> word;
        hist[word]++;
    }

    for (auto &x : hist) {
        if (x.second == 1) { continue; }
        cout << x.first << " " << x.second << endl;
    }
}