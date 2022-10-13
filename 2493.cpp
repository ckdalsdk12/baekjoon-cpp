#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    stack<pair<int, int>> towers;
    int n;
    cin >> n;

    for (int i = 1; i < n+1; i++) {
        int tower;
        cin >> tower;
        
        if (towers.empty()) {
            cout << "0" << " ";
            towers.push(make_pair(tower, i));
        }
        else if (towers.top().first > tower) {
            cout << towers.top().second << " ";
            towers.push(make_pair(tower, i));
        }
        else if (towers.top().first < tower) {
            while (!towers.empty() && towers.top().first < tower) {
                towers.pop();
            }
            if (!towers.empty())
                cout << towers.top().second << " ";
            else cout << "0" << " ";
            towers.push(make_pair(tower, i));
        }
    }

	return 0;
}