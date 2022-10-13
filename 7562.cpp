#include <bits/stdc++.h>

using namespace std;

int board[300][300];
int visited[300][300];

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        fill_n(board[0], 300*300, 0);
        fill_n(visited[0], 300*300, -1);
        queue<pair<int, int>> Q;
        int count = 0;

        int l;
        cin >> l;

        int curX, curY;
        cin >> curX >> curY;

        board[curX][curY] = 1;
        visited[curX][curY] = 0;
        Q.push({curX, curY});

        int destX, destY;
        cin >> destX >> destY;

        int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
        int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            if (cur.first == destX && cur.second == destY) {
                cout << visited[destX][destY] << "\n";
            }
            for (int xy = 0; xy < 8; xy++) {
                int nx = cur.first + dx[xy];
                int ny = cur.second + dy[xy];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if (board[nx][ny] == 0 && visited[nx][ny] < 0) {
                    count = visited[cur.first][cur.second] + 1;
                    visited[nx][ny] = count;
                    Q.push({nx, ny});
                }
            }
        }
    }
    
    
    // 디버깅
    // cout << "\n";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << board[i][j];
    //     }
    //     cout << "\n";
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << days[i][j];
    //     }
    //     cout << "\n";
    // }

	return 0;
}