#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    int count = 0;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        stack<char> cStack;
        string str;
        cin >> str;
        for (char c : str) {
            if (cStack.empty()) {
                cStack.push(c);
            }
            else {
                if (c == 'A') {
                    if (cStack.top() == 'A') {
                        cStack.pop();
                    }
                    else {
                        cStack.push(c);
                    }
                }
                else if (c == 'B') {
                    if (cStack.top() == 'B') {
                        cStack.pop();
                    }
                    else {
                        cStack.push(c);
                    }
                }
            }
        }
        if (cStack.empty()) {
            count++;
        }
    }
    cout << count;

	return 0;
}