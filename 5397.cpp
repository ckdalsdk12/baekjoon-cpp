#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        list<char> password;
        list<char>::iterator cur = password.end();

        for (char c : str) {
            if (c == '<') {
                if (cur != password.begin())
                    cur--;
            }
            else if (c == '>') {
                if (cur != password.end())
                    cur++;
            }
            else if (c == '-') {
                if (cur != password.begin()) {
                    cur--;
                    cur = password.erase(cur);
                }
            }
            else password.insert(cur, c);
        }
        for (char c : password) {
            cout << c;
        }
        cout << "\n";
    }

	return 0;
}