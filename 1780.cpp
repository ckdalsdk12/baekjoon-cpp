#include <bits/stdc++.h>

using namespace std;

int paper[2187][2187];
int cnt[3];

void check(int x, int y, int n) {
    bool cut = false;
    for (int i = x; i < x+n; i++) {
        for (int j = y; j < y+n; j++) {
            if (paper[i][j] != paper[x][y]) {
                cut = true;
            }
        }
    }
    if (cut == false) {
        cnt[paper[x][y]+1]++;
        return;
    }
    else if (cut == true) {
        int cutN = n / 3;
        for (int cutI = 0; cutI < 3; cutI++) {
            for (int cutJ = 0; cutJ < 3; cutJ++) {
                check(cutI*cutN+x, cutJ*cutN+y, cutN);
            }
        }
    }
}

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    check(0, 0, n);

    for (int i : cnt) {
        cout << i << "\n";
    }

	return 0;
}