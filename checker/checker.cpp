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

void testCases(string name, int caseStart, int caseEnd, const string &exePath) {
    
    for (int i = caseStart; i <= caseEnd; i++) {
        cout << "Test Case: " << i << endl;
        string dir = name + "." + to_string(i) + ".";
        
        string inFile  = "input/"  + dir + "in";
        string outFile = "output/" + dir + "sol";
        string tmpFile = "temp_output.txt";
        
        ifstream fout(outFile);
        if (!fout.is_open()) {
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

        ifstream ansFile(tmpFile);
        vector<string> answer;
        string word;
        while (ansFile >> word) answer.push_back(word);
        
        answerCheck(fout, answer);
        
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