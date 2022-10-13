#include <bits/stdc++.h>

using namespace std;

int board[100][100][100];
int days[100][100][100];

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    fill_n(days[0][0], pow(100, 3), -1);

    queue<tuple<int, int, int>> Q;
    int max = 0;
    int n, m, h;
    cin >> m >> n >> h;
    for(int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int tomato;
                cin >> tomato;
                board[k][i][j] = tomato;
                if (tomato == 1) {
                    Q.push({i, j, k});
                    days[k][i][j] = 0;
                }
                else if (tomato == -1) {
                    days[k][i][j] = -2;
                }
            }
        }
    }

    int x[6] = {0, 0, 1, 0, 0, -1};
    int y[6] = {0, 1, 0, 0, -1, 0};
    int z[6] = {1, 0, 0, -1, 0, 0};

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int xyz = 0; xyz < 6; xyz++) {
            int nx = get<0>(cur) + x[xyz];
            int ny = get<1>(cur) + y[xyz];
            int nz = get<2>(cur) + z[xyz];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) {
                continue;
            }
            if (board[nz][nx][ny] == 0 && days[nz][nx][ny] == -1) {
                Q.push({nx, ny, nz});
                int dayPlus = days[get<2>(cur)][get<0>(cur)][get<1>(cur)]+1;
                days[nz][nx][ny] = dayPlus;
                if (max < dayPlus) {
                    max = dayPlus;
                }
            }
        }
    }
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (days[k][i][j] == -1) {
                    cout << -1;
                    return 0;
                }
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