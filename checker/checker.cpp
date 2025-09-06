#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> icecream(ifstream &fin) {
    vector<int> result;

    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    
    int n, m, start, s, a, x, p;
    fin >> n >> m >> start;
    
    vector<pair<int, int>> changes;
    for (int i = 0; i < n; i++) {
        fin >> a >> s;
        changes.push_back({a, s});
    }
    sort(changes.begin(), changes.end());
    
    map<int, pair<int,int>> segment; // {money at day 'a': {a, rate} } of the start of segement (3: 0, 3 | 12: 3, 2 | 16: 5, 5)
    map<int, int> dayIncome; // {day: money} of the start of segment (0: 3 | 3: 12 | 5: 16)
    int day = 0;
    int currentRate = start;
    int totalMoney = 0;
    segment[start] = {day, currentRate};
    dayIncome[day] = start;
    for (auto &[a, s] : changes) {
        totalMoney += currentRate * (a - day);
        segment[totalMoney] = {a - 1, s};
        dayIncome[a - 1] = totalMoney;
        day = a;
        currentRate = s; 
    }
    
    auto segmentSafePrev = [&](int key) {
        auto it = segment.lower_bound(key);
        if (it == segment.begin()) return it;
        return prev(it);
    };
    
    for (int i = 0; i < m; i++) {
        fin >> p >> x;
        auto itX = dayIncome.lower_bound(x);
        
        int moneyX;
        if (itX == dayIncome.end()) {
            moneyX = totalMoney + (x - day) * currentRate;
        } else {
            auto it = segment.lower_bound(prev(itX)->second);
            auto [money, pv] = *it;
            auto [startDay, rate] = pv;
            moneyX = money + (x - startDay) * rate;
        }
        
        int target = moneyX >= p ? p : p + moneyX; // aims for 'target + p' if reset occurs before reaching 'p' else
        auto itP = segmentSafePrev(target); // prevents moving iter beyond begin (case p < start)
        auto [money, pv] = *itP;
        auto [startDay, rate] = pv;
        // cout << startDay + (target - money + rate - 1) / rate << " "; // calculate day needed within segment range
        result.push_back(startDay + (target - money + rate - 1) / rate);
    }
    return result;
}

void answerCheck(ifstream &fout, vector<int> &answer) {
    int key;
    bool mismatch = false;
    int i = 0;
    while (fout >> key) {
        if (key != answer[i]) {
            cout << "Mismatch!: " << answer[i] << " - " << key << endl;
            mismatch = true;
        }
        i++;
    }
    if (!mismatch) cout << "Answers are correct!";
}

int main() {

    string name = "d65_q1c_ice_cream";
    int caseNum = 10; 
    string dir = name + "." + to_string(caseNum) + ".";
    ifstream fin("input/" + dir + "in");
    ifstream fout("output/" + dir + "sol");

    vector<int> answer = icecream(fin);
    
    answerCheck(fout, answer);
}