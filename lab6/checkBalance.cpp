#include <iostream>
#include <stack>
#include <string>
#include<math.h>
using namespace std;

class Node {
private:
    stack<char> st; // FIXED: Stack should store characters, not integers

public:
    bool checkBalance(string s);
};

bool Node::checkBalance(string s) {

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
            if (st.empty()) {
                return false; // No matching opening bracket
            }
            char x = st.top(); // FIXED: Get top element before popping
            st.pop();
            if ((s[i] == '}' && x != '{') || (s[i] == ']' && x != '[') || (s[i] == ')' && x != '(')) {
                return false; // Mismatched bracket
            }
        }
    }
    return st.empty(); // If stack is empty, it's balanced
}

int main() {
    Node obj;
    while (true) {
        int choice;
        cout << "1. Check balance" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // FIXED: Clear the input buffer

        switch (choice) {
            case 1: {
                string s;
                cout << "Enter the string: ";
                getline(cin, s); // FIXED: Take full-line input
                if (obj.checkBalance(s)) {
                    cout << "Balanced" << endl;
                } else {
                    cout << "Not Balanced" << endl;
                }
                break;
            }
            case 2:
                exit(0);
            default:
                cout << "Invalid choice! Try again." << endl;
				break;
        }
    }
}
