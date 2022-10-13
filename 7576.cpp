#include <bits/stdc++.h>

using namespace std;

int board[1000][1000];
int days[1000][1000];

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    fill_n(days[0], 1000000, -1);

    queue<pair<int, int>> Q;
    int max = 0;
    int n, m;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tomato;
            cin >> tomato;
            board[i][j] = tomato;
            if (tomato == 1) {
                Q.push({i, j});
                days[i][j] = 0;
            }
            else if (tomato == -1) {
                days[i][j] = -2;
            }
        }
    }

    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int xy = 0; xy < 4; xy++) {
            int nx = cur.first + x[xy];
            int ny = cur.second + y[xy];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (board[nx][ny] == 0 && days[nx][ny] == -1) {
                Q.push({nx, ny});
                int dayPlus = days[cur.first][cur.second]+1;
                days[nx][ny] = dayPlus;
                if (max < dayPlus) {
                    max = dayPlus;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (days[i][j] == -1) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << max;
    
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