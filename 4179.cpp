#include <bits/stdc++.h>

using namespace std;

char maze[1000][1000];
int jihun[1000][1000];
int fire[1000][1000];

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    queue<pair<int, int>> jihunQ;
    queue<pair<int, int>> fireQ;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            char c = str[j];
            maze[i][j] = c;
            if (c == '#') {
                jihun[i][j] = -1;
                fire[i][j] = -1;
            }
            else if (c == 'J') {
                jihun[i][j] = 1;
                jihunQ.push({i, j});
            }
            else if (c == 'F') {
                fire[i][j] = 1;
                fireQ.push({i, j});
            }
        }
    }

    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};

    while (!fireQ.empty()) {
        pair<int, int> cur = fireQ.front(); fireQ.pop();
        for (int xy = 0; xy < 4; xy++) {
            int nx = cur.first + x[xy];
            int ny = cur.second + y[xy];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (fire[nx][ny] == -1) {
                continue;
            }
            if (fire[nx][ny] == 0) {
                fireQ.push({nx, ny});
                fire[nx][ny] = fire[cur.first][cur.second]+1;
            }
        }
    }

    while (!jihunQ.empty()) {
        pair<int, int> cur = jihunQ.front(); jihunQ.pop();
        for (int xy = 0; xy < 4; xy++) {
            int nx = cur.first + x[xy];
            int ny = cur.second + y[xy];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << jihun[cur.first][cur.second] << "\n";
                return 0;
            }
            if (jihun[nx][ny] == -1) {
                continue;
            }
            if (fire[nx][ny] != 0 && jihun[cur.first][cur.second]+1 >= fire[nx][ny]) {
                continue;
            }
            if (jihun[nx][ny] == 0) {
                jihunQ.push({nx, ny});
                jihun[nx][ny] = jihun[cur.first][cur.second]+1;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    
    // 디버깅
    // cout << "\n";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << maze[i][j];
    //     }
    //     cout << "\n";
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << jihun[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << fire[i][j] << " "; 
    //     }
    //     cout << "\n";
    // }

	return 0;
}