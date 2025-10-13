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

bool runWithTimeout(const string &exe, const string &inFile, const string &tmpFile, int timeoutMs) {
    // Open input and output files
    HANDLE hIn  = CreateFileA(inFile.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    HANDLE hOut = INVALID_HANDLE_VALUE;

    for (int attempt = 0; attempt < 5 && hOut == INVALID_HANDLE_VALUE; ++attempt) {
        hOut = CreateFileA(tmpFile.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hOut == INVALID_HANDLE_VALUE) Sleep(50); // retry after a short delay
    }
    if (hOut == INVALID_HANDLE_VALUE) {
        cerr << "Failed to open tmp file after retries: " << GetLastError() << "\n";
        return false;
    }

    // Make handles inheritable
    SetHandleInformation(hIn, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);
    SetHandleInformation(hOut, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);

    if (hIn == INVALID_HANDLE_VALUE || hOut == INVALID_HANDLE_VALUE) {
        cerr << "Failed to open " << (hIn == INVALID_HANDLE_VALUE ? "input" : "tmp")  << " file\n";
        DeleteFileA(tmpFile.c_str());
        return false;
    }

    // Setup process startup info with redirected stdin/stdout
    STARTUPINFOA si = { sizeof(si) };
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdInput = hIn;
    si.hStdOutput = hOut;
    si.hStdError = GetStdHandle(STD_ERROR_HANDLE);

    PROCESS_INFORMATION pi;

    // Build command: just the solution exe, no args needed
    string cmd = "\"" + exe + "\"";

    // Starts a process
    if (!CreateProcessA(
            NULL,
            const_cast<char*>(cmd.c_str()), // full cmd line
            NULL, NULL, TRUE,
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
        CloseHandle(hIn);
        CloseHandle(hOut);
        return false; // Time limit exceeds
    }

    // Clean up
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    CloseHandle(hIn);
    CloseHandle(hOut);
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
        
        ifstream fout(outFile), fin(inFile);
        if (!fout.good() || !fin.good()) {
            cout << "Test Case not found. Skipping... " << (!fin.good() ? "(input)\n\n" : "(output)\n\n");
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

bool compileSolution(const string &problemCpp, const string &exeName) {
    string cmd = "g++ \"" + problemCpp   + "\" -O2 -o \"" + exeName + "\"";

    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    if (!CreateProcessA(
            NULL,
            const_cast<char*>(cmd.c_str()),
            NULL, NULL, FALSE,
            CREATE_NO_WINDOW, NULL, NULL,
            &si, &pi)) {
        cerr << "Failed to start compiler process\n";
        return false;
    }

    DWORD result = WaitForSingleObject(pi.hProcess, 10000); // 10 sec timeout

    if (result == WAIT_TIMEOUT) {
        TerminateProcess(pi.hProcess, 1);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        cerr << "Compilation timed out!\n";
        return false;
    }

    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    if (exitCode != 0) {
        cerr << "Compilation failed!\n";
        return false;
    }

    return true;
}

int main() {
    string problemCpp = "../wallPaint.cpp";
    string problemExe = "problem.exe";
    if (!compileSolution(problemCpp, problemExe)) return 1;

    testCases("d67_q1b_wall_paint", 6, 20, problemExe);
}