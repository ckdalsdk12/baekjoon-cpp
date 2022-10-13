#include <bits/stdc++.h>

using namespace std;

int person[1000][1000];
int fire[1000][1000];

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string building[1000];
        fill_n(person[0], 1000*1000, -1);
        fill_n(fire[0], 1000*1000, -1);
        queue<pair<int, int>> pQ;
        queue<pair<int, int>> fQ;
        bool escape = false;
        int escapeTime = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int w, h;
        cin >> h >> w;
        for (int i = 0; i < w; i++) {
            cin >> building[i];
        }

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (building[i][j] == '#') {
                    person[i][j] = -2;
                    fire[i][j] = -2;
                }
                else {
                    if (building[i][j] == '@') {
                        person[i][j] = 0;
                        pQ.push({i, j});
                    }
                    if (building[i][j] == '*') {
                        fire[i][j] = 0;
                        fQ.push({i, j});
                    }
                }
            }
        }

        while (!fQ.empty()) {
            auto cur = fQ.front(); fQ.pop();
            for (int xy = 0; xy < 4; xy++) {
                int nx = cur.first + dx[xy];
                int ny = cur.second + dy[xy];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if (fire[nx][ny] == -1) {
                    fire[nx][ny] = fire[cur.first][cur.second] + 1;
                    fQ.push({nx, ny});
                }
            }
        }

        while (!pQ.empty()) {
            if (escape == true) break;
            auto cur = pQ.front(); pQ.pop();
            for (int xy = 0; xy < 4; xy++) {
                int nx = cur.first + dx[xy];
                int ny = cur.second + dy[xy];
                int curX = cur.first;
                int curY = cur.second;
                int curPlusOne = person[curX][curY] + 1;
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                    escape = true;
                    // escapeTime = person[cur.first][cur.second] + 1;
                    cout << person[cur.first][cur.second] + 1 << "\n";
                    break;
                }
                if ((fire[nx][ny] <= curPlusOne) && fire[nx][ny] != -1) {
                    continue;
                }
                if (person[nx][ny] == -1) {
                    person[nx][ny] = curPlusOne;
                    pQ.push({nx, ny});
                }
            }
        }

        if (escape == false) {
            cout << "IMPOSSIBLE\n";
        }
        // else if (escape == true) {
        //     cout << escapeTime << "\n";
        // }

        // 디버깅
        // cout << "\n";
        // for (int i = 0; i < w; i++) {
        //     for (int j = 0; j < h; j++) {
        //         cout << building[i][j];
        //     }
        //     cout << "\n";
        // }

        // for (int i = 0; i < w; i++) {
        //     for (int j = 0; j < h; j++) {
        //         cout << person[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        // for (int i = 0; i < w; i++) {
        //     for (int j = 0; j < h; j++) {
        //         cout << fire[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }

	return 0;
}