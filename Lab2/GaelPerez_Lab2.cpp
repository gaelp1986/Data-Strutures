#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<char> s;
    string line;
    cout << "Enter an expression: ";
    getline(cin, line);
    bool balanced = true;

    for (int i = 0; i < line.size(); i++) {
        char c = line[i];
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                balanced = false;
                break;
            }
            else if (!(c == ')' && s.top() == '(' ||
                       c == '}' && s.top() == '{' ||
                       c == ']' && s.top() == '[')) {
                balanced = false;
                break;
            }
            else {
                s.pop();
            }
        }
    }

    if (balanced && s.empty()) {
        cout << "Balanced" << endl;
    }
    else {
        cout << "Not Balanced" << endl;
    }
    return 0;
}