#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    stack<char> stick;
    string mix;
    char lasted = ' ';
    int count = 0;

    cin >> mix;

    for (char c : mix) {
        if (c == '(') {
            stick.push(c);
        }
        else if (c == ')') {
            if (lasted == '(') {
                if (!stick.empty()) {
                    stick.pop();
                    count += stick.size();
                }
            }
            else if (lasted == ')') {
                stick.pop();
                count++;
            }
        }
        lasted = c;
    }

    cout << count;

	return 0;
}