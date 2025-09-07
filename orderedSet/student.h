#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> seen;
    for (T a : A) {
        v.push_back(a);
        seen.insert(a);
    }

    for (T b : B) {
        if (seen.count(b)) {
            continue;
        }
        v.push_back(b);
    }

    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> match;
    for (T b : B) {
        match.insert(b);
    }

    for (T a : A) {
        if (match.count(a)) {
            v.push_back(a);
        }
    }

    return v;
}
