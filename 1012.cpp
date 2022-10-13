#include <bits/stdc++.h>

using namespace std;

int ground[50][50];
int visited[50][50];

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while (t--) {
        fill_n(ground[0], 50*50, 0);
        fill_n(visited[0], 50*50, 0);
        queue<pair<int, int>> Q;
        int count = 0;
        int m, n, k;
        cin >> m >> n >> k;

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            ground[x][y] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ground[i][j] == 1 && visited[i][j] == 0) {
                    Q.push({i, j});
                    visited[i][j] = 1;
                    count++;
                    while (!Q.empty()) {
                        auto cur = Q.front(); Q.pop();
                        for (int xy = 0; xy < 4; xy++) {
                            int nx = cur.first + dx[xy];
                            int ny = cur.second + dy[xy];
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if (visited[nx][ny] || ground[nx][ny] != 1) continue;
                            visited[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                }               
            }
        }

        cout << count << "\n";

        // 디버깅
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << ground[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }

	return 0;
}