#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    // int test = 0; // 디버깅

    while (true) {
        bool pass = false;
        // test++; // 디버깅
        stack<char> cStack;
        string str;
        getline(cin, str);
        if (str == ".") {
            break;
        }
        else {
            for (char c : str) {
                if (c == '(' || c == '[') {
                    cStack.push(c);
                }
                else if (c == ')') {
                    if (!cStack.empty()) {
                        if (cStack.top() == '(') {
                            cStack.pop();
                        }
                        else {
                            cout << "no\n";
                            pass = true;
                            // cout << test << "\n"; // 디버깅
                            break;
                        }
                    }
                    else {
                        cout << "no\n";
                        pass = true;
                        // cout << test << "\n"; // 디버깅
                        break;
                    }
                }
                else if (c == ']') {
                    if (!cStack.empty()) {
                        if (cStack.top() == '[') {
                            cStack.pop();
                        }
                        else {
                            cout << "no\n";
                            pass = true;
                            // cout << test << "\n"; // 디버깅
                            break;
                        }
                    }
                    else {
                        cout << "no\n";
                        pass = true;
                        // cout << test << "\n"; // 디버깅
                        break;
                    }
                }
                else if (c == '.') {
                    break;
                }
            }
            if (cStack.empty() && pass == false) {
                cout << "yes\n";
                // cout << test << "\n"; // 디버깅
            }
            else if (!cStack.empty() && pass == false) {
                cout << "no\n";
                // cout << test << "\n"; // 디버깅
            }
        }
    }

	return 0;
}