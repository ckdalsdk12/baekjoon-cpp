#include <bits/stdc++.h>

using namespace std;

int board[100][100];
int dist[100][100];

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    queue<pair<int, int>> Q;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            board[i][j] = str[j]-'0';
        }
    }

    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};

    Q.push({0, 0});
    dist[0][0] = 1;

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int xy = 0; xy < 4; xy++) {
            int nx = cur.first + x[xy];
            int ny = cur.second + y[xy];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (board[nx][ny] == 1 && dist[nx][ny] < 1) {
                Q.push({nx, ny});
                dist[nx][ny] = dist[cur.first][cur.second]+1;
            }
        }
    }

    cout << dist[n-1][m-1] << "\n";
    
    // 디버깅
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << board[i][j];
    //     }
    //     cout << "\n";
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << dist[i][j];
    //     }
    //     cout << "\n";
    // }

	return 0;
}