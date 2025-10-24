#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int main() {
    string recentTestcases = "recentTestcases.txt";
    string folderName = "testcase";

    ifstream fin(recentTestcases);
    string testcase;
    fin >> testcase;
    fin.close();

    if (testcase.empty()) {
        cerr << "Error: testcases name is empty";
        return 1;
    }

    
    fs::path dir = fs::current_path() / folderName;
    size_t deleted = 0;
    for (const auto &entry : fs::directory_iterator(dir)) {
        if (entry.is_regular_file()) {
            string filename = entry.path().filename().string();

            if (!filename.rfind(testcase, 0)) {
                try {
                    fs::remove(entry.path());
                    cout << "Deleted " << filename << endl;
                    ++deleted;
                } catch (const exception &e) {
                    cerr << "Failed to delete " << filename << ": " << e.what() << endl;
                }
            }
        }
    }

    cout << "Deleted " << deleted << " file(s)!";
}