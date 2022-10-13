#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    deque<pair<int, int>> deq;

    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;

        if (deq.empty()) {
            deq.push_front({element, i});
        }
        else {
            if (deq.front().second + l == i) {
                deq.pop_front();
            }
            
            if (!deq.empty() && deq.front().first > element) {
                while (!deq.empty()) {
                    deq.pop_back();
                }
                deq.push_front({element, i});
            }
            else {
                while (!deq.empty() && deq.back().first >= element) {
                    deq.pop_back();
                }
                deq.push_back({element, i});
            }
        }
        cout << deq.front().first << " ";
    }

	return 0;
}