#include <bits/stdc++.h>

using namespace std;

int paper[500][500];
int visited[500][500];

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    int count = 0;
    int maxArea = 0;
    queue<pair<int, int>> Q;
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int area = 0;
            if (paper[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = 1;
                Q.push({i, j});
                count++;
            }
            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop(); area++;
                for (int xy = 0; xy < 4; xy++) {
                    int nx = cur.first + x[xy];
                    int ny = cur.second + y[xy];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (paper[nx][ny] == 1 && visited[nx][ny] == 0) {
                        visited[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    cout << count << "\n" << maxArea;

	return 0;
}