#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> problem(ifstream &fin) {
    vector<T> result;



    return result;
}

template <typename T>
void answerCheck(ifstream &fout, vector<T> &answer) {
    T key;
    bool mismatch = false;
    int i = 0;
    while (fout >> key) {
        if (key != answer[i]) {
            cout << "Mismatch!: " << answer[i] << " - " << key << endl;

            mismatch = true;
        }
        i++;
    }
    if (!mismatch) cout << "Answers are correct!" << endl;
}

template <typename T>
void testCases(string name, int caseStart, int caseEnd) {
    
    for (int i = caseStart; i <= caseEnd; i++) {
        cout << "Test Case: " << i << endl;
        string dir = name + "." + to_string(i) + ".";
    
        ifstream fin("input/" + dir + "in");
        ifstream fout("output/" + dir + "sol");
        
        vector<T> answer = problem(fin);
    
        answerCheck(fout, answer);
        cout << endl;
    }
}

int main() {
    
    testCases<string>("d66_q1c_company_department", 9, 16);
}