#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <sstream>

using namespace std;

void problem() {
   
}

void answerCheck(ifstream &fout, vector<string> &answer) {
    string key;
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

template <typename F>
vector<string> runAndCapture(F func, const string &inputFile) {
    // Save original buffers
    streambuf* oldCout = cout.rdbuf();
    streambuf* oldCin = cin.rdbuf();

    // Redirect cout to buffer
    ostringstream outBuffer;
    cout.rdbuf(outBuffer.rdbuf());

    // Redirect cin to file
    ifstream fin(inputFile);
    cin.rdbuf(fin.rdbuf());

    // Run problem (which now just uses cin/cout)
    func();

    // Restore cin and cout
    cout.rdbuf(oldCout);
    cin.rdbuf(oldCin);

    // Split captured output
    vector<string> result;
    istringstream iss(outBuffer.str());
    string word;
    while (iss >> word) result.push_back(word);

    return result;
}

template <typename F>
void testCases(string name, int caseStart, int caseEnd, F func) {
    
    for (int i = caseStart; i <= caseEnd; i++) {
        cout << "Test Case: " << i << endl;
        string dir = name + "." + to_string(i) + ".";
        
        string inFile  = "input/"  + dir + "in";
        string outFile = "output/" + dir + "sol";

        ifstream fout(outFile);
        if (!fout.is_open()) {
            cout << "Test Case not found. Skipping..." << endl;
            continue;
        }

        auto start = chrono::high_resolution_clock::now();
        vector<string> answer = runAndCapture(func, inFile);
        auto end = chrono::high_resolution_clock::now();
        
        answerCheck(fout, answer);
        
        chrono::duration<double> duration = end - start;
        cout << "Execution time: " << duration.count() << " s" << endl;
    
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    testCases("d62_q1b_queue_count", 1, 1, problem);
}