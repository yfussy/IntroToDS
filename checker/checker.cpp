#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <fstream>
#include <algorithm>
#include <chrono>

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

        
        auto start = chrono::high_resolution_clock::now();
        vector<T> answer = problem<T>(fin);
        auto end = chrono::high_resolution_clock::now();
        
        answerCheck(fout, answer);
        
        chrono::duration<double> duration = end - start;
        cout << "Execution time: " << duration.count() << " s" << endl;
    
        cout << endl;
    }
}

int main() {
    
    testCases<string>("d66_q1a_topsale", 1, 1);
}