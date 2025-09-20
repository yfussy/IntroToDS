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
#include <windows.h>

using namespace std;

void problem() {
   int n, m, x, c, d;
    cin >> n >> m;

    map<int, pair<int, int>> order;
    map<int, set<pair<int, int>>> paint;
    for (int i = 0; i < 2 * m; i++) {
        cin >> x >> c >> d;
        if (!d) {
            order[c].first = x;
        } else {
            order[c].second = x;
        }
    }

    for (auto &o : order) {
        auto &[start, end] = o.second;
        int layer = 0;
        while (true) {
            auto &paintLayer = paint[layer];

            // Empty layer
            if (!paintLayer.size()) {
                paintLayer.insert({start, end});
                break;
            }

            auto it = paintLayer.lower_bound({start, end});
            if (it != paintLayer.begin()) it = prev(it);

            // Going up the layers
            if (it->first < start && it->second > end) {
                layer++;
                continue;
            }

            if (it->second < start) {
                // check adjacent left
                if (start - it->second == 1) {
                    start = it->first;
                    it = paintLayer.erase(it);
                } else {
                    it = next(it);
                }

                if (it == paintLayer.end() || it->first > end) {
                    // check adjacent right
                    if (it != paintLayer.end() && it->first - end == 1) {
                        end = it->second;
                        paintLayer.erase(it);
                    }
                    paintLayer.insert({start, end});
                }
            }
            break;
        }
    }

    cout << paint.size();
}

bool runWithTimeout(const string &exe, const string &inFile, const string &tmpFile, int timeoutMs) {
    // Builds the cmd line for sub process in solver mode
    string cmd = "\"" + exe + "\" --solve " + inFile + " " + tmpFile;

    // Info for starting a process
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi; // handles IDs

    // Starts a process
    if (!CreateProcessA(
            NULL,
            const_cast<char*>(cmd.c_str()), // full cmd line
            NULL, NULL, FALSE,
            CREATE_NO_WINDOW, NULL, NULL,
            &si, &pi)) {
        cerr << "Failed to start process\n";
        return false;
    }

    // Wait for the process to finish
    DWORD result = WaitForSingleObject(pi.hProcess, timeoutMs); // timeoutMs: time willing to wait

    // If time is out, terminate the process
    if (result == WAIT_TIMEOUT) {
        TerminateProcess(pi.hProcess, 1);
        
        // Clean up
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        return false; // Time limit exceeds
    }

    // Clean up
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return true; // Finished normally
}

vector<string> readOutput(const string &fileName) {
    ifstream fin(fileName);
    vector<string> result;
    string word;
    while (fin >> word) result.push_back(word);
    return result;
}

void answerCheck(vector<string> &expected, vector<string> &answer) {
    bool mismatch = false;
    if (expected.size() != answer.size()) {
        cout << "Size Mismatch!: " << answer.size() << " (Expected: " << expected.size() << ")\n";
        return;
    }

    for (size_t i = 0; i < expected.size(); ++i) {
        if (expected[i] != answer[i]) {
            cout << "Mismatch!: " << answer[i] << " (Expected: " << expected[i] << ")\n";
            mismatch = true;
        }
    }

    if (!mismatch) cout << "Answer are correct!\n";
}

void testCases(string name, int caseStart, int caseEnd, const string &exePath) {
    
    for (int i = caseStart; i <= caseEnd; i++) {
        cout << "Test Case: " << i << endl;
        string dir = name + "." + to_string(i) + ".";
        
        string inFile  = "input/"  + dir + "in";
        string outFile = "output/" + dir + "sol";
        string tmpFile = "temp_output.txt";
        
        ifstream fout(outFile);
        ifstream fin(inFile);
        if (!fout.good() || !fin.good()) {
            cout << "Test Case not found. Skipping...\n\n";
            continue;
        }

        auto start = chrono::high_resolution_clock::now();
        bool ok = runWithTimeout(exePath, inFile, tmpFile, 1600);
        auto end = chrono::high_resolution_clock::now();

        if (!ok) {
            cout << "Time limit exceeded. Skipping...\n\n";
            continue;
        }
        
        vector<string> expected = readOutput(outFile);
        vector<string> answer = readOutput(tmpFile);
        answerCheck(expected, answer);
        
        chrono::duration<double> duration = end - start;
        cout << "Execution time: " << duration.count() << " s\n\n";
    }
}

// argc: arg counts, argv: arg value
// checker.exe (--solve inFile outFile)
// ----[0]----  --[1]-- --[2]- --[3]-- : argv[]
int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);

    if (argc > 1 && string(argv[1]) == "--solve") {
        // Solver mode
        freopen(argv[2], "r", stdin);
        freopen(argv[3], "w", stdout);
        problem();
        return 0;
    }

    // Checker mode
    string exePath = argv[0];
    testCases("d67_q1b_wall_paint", 6, 20, exePath);
}