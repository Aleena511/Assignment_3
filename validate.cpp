#include <iostream>
#include <vector>
#include <string>
using namespace std;

// checks if a filename contains only allowed characters
bool validCharacters(const string& name) {
    for (char ch : name) {
        if (!( (ch >= 'A' && ch <= 'Z') ||
               (ch >= 'a' && ch <= 'z') ||
               (ch >= '0' && ch <= '9') ||
               ch == '_' || ch == '.' )) {
            return false;
        }
    }
    return true;
}

bool valid_submission(int labNumber, int erp, const vector<string>& files, bool verbose = false) {
    bool allGood = true;

    string expectedZip = "lab" + to_string(labNumber) + "_" + to_string(erp) + ".zip";

    if (verbose) cout << "Validating submission: " << files[0] << endl;

    if (files[0] == expectedZip) {
        if (verbose) cout << "- " << files[0] << " pass" << endl;
    } else {
        if (verbose) cout << "- " << files[0] << " fail" << endl;
        allGood = false;
    }

    for (int i = 1; i < files.size(); i++) {
        string name = files[i];
        bool ok = true;

        if (name.substr(0, 4) != "task") ok = false;

        int numIndex = 4;
        if (numIndex >= name.length() || !(name[numIndex] >= '1' && name[numIndex] <= '9')) {
            ok = false;
        }

        if (name.find(".cpp") == string::npos) {
            ok = false;
        }

        if (!validCharacters(name)) {
            ok = false;
        }

        if (verbose) {
            cout << "- " << name << " " << (ok ? "pass" : "fail") << endl;
        }

        if (!ok) allGood = false;
    }

    if (verbose) {
        cout << endl;
        cout << "Summary for " << files[0] << ": ";
        cout << (allGood ? "All files valid" : "Some files failed") << endl;
        cout << endl;
    }

    return allGood;
}

int main() {
    vector<string> case1 = {"lab8_25985.zip", "task1.cpp", "task2.cpp"};
    vector<string> case2 = {"lab08_25985.zip", "task1.cpp", "task2.cpp"};
    vector<string> case3 = {"lab8_25985.zip", "task01.cpp", "task2.cpp"};
    vector<string> case4 = {"lab8_25985.zip", "task1!.cpp", "task2.cpp"};

    cout << (valid_submission(8, 25985, case1) ? "Valid Submission pass\n" : "Valid Submission fail\n");
    cout << (valid_submission(8, 25985, case2) ? "Invalid Zip Name pass\n" : "Invalid Zip Name fail\n");
    cout << (valid_submission(8, 25985, case3) ? "Invalid Task Name pass\n" : "Invalid Task Name fail\n");
    cout << (valid_submission(8, 25985, case4) ? "Special Character in Task Name pass\n" : "Special Character in Task Name fail\n");

    return 0;
}
