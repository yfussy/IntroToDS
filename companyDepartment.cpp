#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<string, string> employees;
    map<string, set<string>> departments;
    string name, dept;
    for (int i = 0; i < n; i++) {
        cin >> name >> dept;
        employees[name] = dept;
        departments[dept].insert(name);
    }

    int op;
    for (int i = 0; i < m; i++) {
        cin >> op;
        string dept1, dept2;
        switch (op) {
            case 1: {
                cin >> name >> dept;
                departments[employees[name]].erase(name);
                departments[dept].insert(name);
                employees[name] = dept;
                break;
            }
            case 2: {
                cin >> dept1 >> dept2;
                auto empDept1 = departments[dept1];
                for (auto &emp : empDept1) {
                    employees[emp] = dept2;
                }
                departments[dept2].merge(empDept1);
                departments.erase(dept1);
                break;
            }
        }
    }

    for (auto &x : departments) {
        cout << x.first << ": ";
        for (auto &y : x.second) {
            cout << y << " ";
        }
        cout << endl;
    }
}