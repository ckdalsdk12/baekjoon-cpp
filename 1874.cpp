#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    stack<int> s;
    vector<string> v;
    int max = 0;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num > max) {
            int count = num - max;
            for (int j = max+1; j < num+1; j++) {
                s.push(j);
                v.push_back("+\n");
            }
            max = num;
        }
        if (!s.empty()) {
            if (s.top() != num) {
                cout << "NO";
                return 0;
            }
            else {
                s.pop();
                v.push_back("-\n");
            }
        }
    }

    for (auto s : v) {
        cout << s;
    }

	return 0;
}