#include <iostream>
#include <string>
using namespace std;

// helper function to compare characters case-insensitively
bool compareChars(char a, char b) {
    char ca = (a >= 'A' && a <= 'Z') ? a + 32 : a;
    char cb = (b >= 'A' && b <= 'Z') ? b + 32 : b;
    return ca < cb;
}

// returns a new sorted string
string sort_string(const string& str, int n = -1) {
    string result = str;
    int length = result.length();

    if (n < 0 || n > length) {
        n = length;
    }

    // simple selection sort on first n characters
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (compareChars(result[j], result[minIndex])) {
                minIndex = j;
            }
        }
        char temp = result[i];
        result[i] = result[minIndex];
        result[minIndex] = temp;
    }

    return result;
}

// sort string in place
void sort_string_inplace(string& str, int n = -1) {
    int length = str.length();

    if (n < 0 || n > length) {
        n = length;
    }

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (compareChars(str[j], str[minIndex])) {
                minIndex = j;
            }
        }
        char temp = str[i];
        str[i] = str[minIndex];
        str[minIndex] = temp;
    }
}

int main() {
    string userInput;
    int limit;

    cout << "Enter a string: ";
    getline(cin, userInput);

    cout << "Enter number of characters to sort (negative for all): ";
    cin >> limit;

    string newSorted = sort_string(userInput, limit);
    cout << "Sorted string (new): " << newSorted << endl;

    sort_string_inplace(userInput, limit);
    cout << "Sorted string (in place): " << userInput << endl;

    return 0;
}
