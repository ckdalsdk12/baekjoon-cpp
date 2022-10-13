#include <bits/stdc++.h>

using namespace std;

char board[2187][2187];

void star(int x, int y, int n) {
    if (n == 1) {
        return;
    }
    int cutN = n / 3;
    for (int i = cutN+x; i < cutN*2+x; i++) {
        for (int j = cutN+y; j < cutN*2+y; j++) {
            board[i][j] = ' ';
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            star(cutN*i+x, cutN*j+y, cutN);
        }
    }
}

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    fill_n(board[0], 2187*2187, '*');

    int n;
    cin >> n;

    star(0, 0, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }

	return 0;
}