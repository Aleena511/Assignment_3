#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printHelp() {
    cout << "Usage:\n\n";
    cout << "<operator> <num1> <num2>\n\n";
    cout << "Operators:\n";
    cout << "+, -, *, /\n\n";
    cout << "Commands:\n";
    cout << "history show history of all previous operations\n";
    cout << "help display help\n";
    cout << "quit exit program\n";
}

int main() {
    vector<int[4]> history;
    string command;

    cout << "Simple Command-Line Calculator\n";
    cout << "Type 'help' for a list of commands.\n\n";

    while (true) {
        cout << "> ";
        cin >> command;

        if (command == "quit") break;

        else if (command == "help") {
            printHelp();
        }

        else if (command == "history") {
            for (int i = 0; i < history.size(); i++) {
                int first = history[i][0];
                char op = static_cast<char>(history[i][1]);
                int second = history[i][2];
                int result = history[i][3];

                cout << first << " " << op << " " << second << " = " << result << endl;
            }
        }

        else {
            int num1, num2;
            cin >> num1 >> num2;

            int result;
            bool valid = true;

            switch (command[0]) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/':
                    if (num2 == 0) {
                        cout << "Error: Division by zero.\n";
                        valid = false;
                    } else {
                        result = num1 / num2;
                    }
                    break;
                default:
                    cout << "Invalid operator.\n";
                    valid = false;
            }

            if (valid) {
                cout << result << endl;
                int entry[4] = {num1, command[0], num2, result};
                history.push_back(entry);
            }
        }
    }

    return 0;
}
