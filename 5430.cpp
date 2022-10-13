#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    deque<string> deq;
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        bool reverse = false;
        bool error = false;

        string p;
        cin >> p;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        arr.erase(remove(arr.begin(), arr.end(), '['), arr.end());
        arr.erase(remove(arr.begin(), arr.end(), ']'), arr.end());
        istringstream ss(arr);
        string token;
        while (getline(ss, token, ',')) {
            deq.push_back(token);
        }

        for (char c : p) {
            if (c == 'R') {
                reverse = !reverse;
            }
            else if (c == 'D') {
                if (!deq.empty()) {
                    if (reverse == false)
                        deq.pop_front();
                    else deq.pop_back();
                }
                else error = true;
            }
        }

        if (error == true) {
            cout << "error\n";
            continue;
        }
        else {
            cout << "[";
            int size = deq.size();
            for (int j = 0; j < size; j++) {
                if (reverse == false) {
                    cout << deq.front();
                    deq.pop_front();
                }
                else {
                    cout << deq.back();
                    deq.pop_back();
                }

                if (j != size-1) {
                    cout << ",";
                }
            }
            cout << "]\n";
        }
    }

	return 0;
}