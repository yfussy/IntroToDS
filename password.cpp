#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m, l, num;
    int start = 'a';
    cin >> n >> m >> l;
    vector<int> hashKey;
    for (int i = 0; i < l; i++) {
        cin >> num;
        hashKey.push_back(num);
    }

    unordered_set<string> hashedPass;
    string pass;
    for (int i = 0; i < n; i++) {
        cin >> pass;
        for (size_t i = 0; i < l; i++) {
            int shift = (pass[i] - 'a' - hashKey[i]) % 26;
            if (shift < 0) shift += 26;
            pass[i] = 'a' + shift;
            
        }
        hashedPass.insert(pass);
    }   

    for (int i = 0; i < m; i++) {
        cin >> pass;
        if (hashedPass.count(pass)) {
            cout << "Match\n";
        } else {
            cout << "Unknown\n";
        }
    }
}