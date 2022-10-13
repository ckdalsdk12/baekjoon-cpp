#include <bits/stdc++.h>

using namespace std;

char board[3072][6143];

void star(int x, int y, int n) {
    if (n == 3) {
        board[x][y] = '*';
        board[x+1][y-1] = '*';
        board[x+1][y+1] = '*';
        for (int i = y-2; i <= y+2; i++) {
            board[x+2][i] = '*';
        }
        return;
    }
    star(x, y, n/2);
    star(x + n/2, y - n/2, n/2);
    star(x + n/2, y + n/2, n/2);
}

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    fill_n(board[0], 3072*6143, ' ');

    int n;
    cin >> n;

    star(0, n-1, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n-1; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }

	return 0;
}