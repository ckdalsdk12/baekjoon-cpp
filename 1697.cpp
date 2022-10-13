#include <bits/stdc++.h>

using namespace std;

int area[100001];

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    queue<pair<int, int>> Q;
    int n, k;
    cin >> n >> k;

    fill_n(area, 100001, -1);

    area[n] = 0;
    Q.push({n, 0});

    if (n == k) {
        cout << 0;
        return 0;
    }

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int one = cur.first + 1;
        int two = cur.first - 1;
        int three = cur.first * 2;
        int phase = cur.second + 1;
        if (one == k || two == k || three == k) {
            cout << phase;
            return 0;
        }
        if (one <= 100000 && one >= 0) {
            if (area[one] < 0) {
                Q.push({one, phase});
                area[one] = phase;
            }
        }
        if (two <= 100000 && two >= 0) {
            if (area[two] < 0) {
                Q.push({two, phase});
                area[two] = phase;
            }
        }
        if (three <= 100000 && three >= 0) {
            if (area[three] < 0) {
                Q.push({three, phase});
                area[three] = phase;
            }
        }
    }

	return 0;
}