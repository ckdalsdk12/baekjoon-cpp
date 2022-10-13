#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    stack<char> cStack;
    string str;
    int temp = 1;
    int result = 0;
    char lasted = ' ';

    cin >> str;
    
    for (char c : str) {
        if (c == '(') {
            temp *= 2;
            cStack.push(c);
        }
        else if (c == '[') {
            temp *= 3;
            cStack.push(c);
        }
        else if (c == ')') {
            if (cStack.empty() || cStack.top() == '[') {
                cout << 0;
                return 0;
            }
            if (lasted == '(') {
                result += temp;
            }
            temp /= 2;
            cStack.pop();
        }
        else if (c == ']') {
            if (cStack.empty() || cStack.top() == '(') {
                cout << 0;
                return 0;
            }
            if (lasted == '[') {
                result += temp;
            }
            temp /= 3;
            cStack.pop();
        }
        lasted = c;
    }

    if (!cStack.empty()) {
        cout << 0;
        return 0;
    }

    cout << result;

	return 0;
}