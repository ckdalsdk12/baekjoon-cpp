#include <bits/stdc++.h>

using namespace std;

string pic[100];
int normal[100][100];
int colorWeak[100][100];

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    queue<pair<int, int>> Q;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int nCount = 0;
    int cwCount = 0;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> pic[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (normal[i][j] == 0) {
                Q.push({i, j});
                normal[i][j] = 1;
                nCount++;
            }
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for (int xy = 0; xy < 4; xy++) {
                    int nx = cur.first + dx[xy];
                    int ny = cur.second + dy[xy];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (pic[nx][ny] == pic[cur.first][cur.second] && normal[nx][ny] == 0) {
                        Q.push({nx, ny});
                        normal[nx][ny] = 1;
                    }
                }
            }
        }
    }

    while (!Q.empty()) {
        Q.pop();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (colorWeak[i][j] == 0) {
                Q.push({i, j});
                colorWeak[i][j] = 1;
                cwCount++;
            }
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for (int xy = 0; xy < 4; xy++) {
                    int nx = cur.first + dx[xy];
                    int ny = cur.second + dy[xy];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    char curChar = pic[cur.first][cur.second];
                    if (curChar == 'R' || curChar == 'G') {
                        if ((pic[nx][ny] == 'R' || pic[nx][ny] == 'G') && colorWeak[nx][ny] == 0) {
                            Q.push({nx, ny});
                            colorWeak[nx][ny] = 1;
                        }
                    }
                    else {
                        if (pic[nx][ny] == pic[cur.first][cur.second] && colorWeak[nx][ny] == 0) {
                            Q.push({nx, ny});
                            colorWeak[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }

    cout << nCount << " " << cwCount;

	return 0;
}