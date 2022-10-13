#include <bits/stdc++.h>

using namespace std;

int paper[128][128];
int cnt[2];

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
        cnt[paper[x][y]]++;
        return;
    }
    else if (cut == true) {
        int cutN = n / 2;
        for (int cutI = 0; cutI < 2; cutI++) {
            for (int cutJ = 0; cutJ < 2; cutJ++) {
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