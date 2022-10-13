#include <bits/stdc++.h>

using namespace std;

string image[64];

void check(int x, int y, int n) {
    bool cut = false;
    for (int i = x; i < x+n; i++) {
        for (int j = y; j < y+n; j++) {
            if (image[i][j] != image[x][y]) {
                cut = true;
            }
        }
    }
    if (cut == false) {
        cout << image[x][y];
        return;
    }
    else if (cut == true) {
        cout << "(";
        int cutN = n / 2;
        for (int cutI = 0; cutI < 2; cutI++) {
            for (int cutJ = 0; cutJ < 2; cutJ++) {
                check(cutI*cutN+x, cutJ*cutN+y, cutN);
            }
        }
        cout << ")";
    }
}

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> image[i];
    }

    check(0, 0, n);

	return 0;
}