#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    cout << std::fixed << std::setprecision(2);
    int n, id, rating;
    string prof;
    map<int, pair<int, int>> courseRating;
    map<string, pair<int, int>> profRating;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> prof >> rating;
        courseRating[id].first += rating;
        courseRating[id].second++;
        profRating[prof].first += rating;
        profRating[prof].second++;
    }

    rating = 0;
    for (auto &it : courseRating) {
        cout << it.first << " " << (it.second.first + 0.0) / it.second.second << endl;
    }

    rating = 0;
    for (auto &it : profRating) {
        cout << it.first << " " << (it.second.first + 0.0) / it.second.second << endl;
    }
}