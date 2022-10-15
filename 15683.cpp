#include <bits/stdc++.h>

using namespace std;

int office[10][10];
int scannedOffice[10][10];
int n, m;
vector<pair<int, int>> cctv;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// cctv의 x, y 좌표와 방향 매개변수 dir을 받아 탐색. 스캔되는 좌표는 7로 지정.
void scan(int x, int y, int dir) {
    dir %= 4;
    while(true) {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= n || y < 0 || y >= m || scannedOffice[x][y] == 6)
            return;
        if (scannedOffice[x][y] != 0)
            continue;
        scannedOffice[x][y] = 7;
    }
}

int main(int argc, char** argv) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int minBlindSpot = 0;

    // n은 세로크기, m은 가로크기
    cin >> n >> m;

    // office를 입력받으며 cctv면 좌표를 cctv 벡터에 추가.
    // 또한 0(빈공간)일경우 일단 사각지대에 포함.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> office[i][j];
            if (office[i][j] != 0 && office[i][j] != 6) {
                cctv.push_back({i, j});
            }
            if (office[i][j] == 0) {
                minBlindSpot++;
            }
        }
    }

    // cctv 방향에 대한 모든 가능성에 대해 반복
    for (int possibility = 0; possibility < (1<<(2*cctv.size())); possibility++) {
        // 배열 복사
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scannedOffice[i][j] = office[i][j];
            }
        }
    
        // tmp에 possibility를 복사하고, tmp를 가장 오른쪽자리부터 분해하여 dir로 만듬. (각 cctv 방향 지정)
        int tmp = possibility;
        for (int i = 0; i < cctv.size(); i++) {
            int dir = tmp % 4;
            tmp /= 4;
            int x = cctv[i].first;
            int y = cctv[i].second;
            // cctv 종류에 따라 정해진 방향에 맞게 탐색
            if (office[x][y] == 1) {
                scan(x, y, dir);
            }
            else if (office[x][y] == 2) {
                scan(x, y, dir);
                scan(x, y, dir+2);
            }
            else if (office[x][y] == 3) {
                scan(x, y, dir);
                scan(x, y, dir+1);
            }
            else if (office[x][y] == 4) {
                scan(x, y, dir);
                scan(x, y, dir+1);
                scan(x, y, dir+2);
            }
            else if (office[x][y] == 5) {
                scan(x, y, dir);
                scan(x, y, dir+1);
                scan(x, y, dir+2);
                scan(x, y, dir+3);
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (scannedOffice[i][j] == 0) {
                    count++;
                }
            }
        }
        minBlindSpot = min(count, minBlindSpot);
    }

    cout << minBlindSpot;

    return 0;
}