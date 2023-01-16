#include <bits/stdc++.h>

using namespace std;

int n, m; // 연구소 크기
int lab[8][8]; // 연구소 배열
int maxSafeArea = 0; // 최대 안전 영역 크기
queue<pair<int, int>> virus; // 초기 바이러스 위치 큐
vector<pair<int, int>> blank; // 초기 빈 공간 위치 큐
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// bfs로 바이러스 전파
int bfs() {
    queue<pair<int, int>> q;
    q = virus; // q 큐에 바이러스 큐 복사
    int visited[8][8];
    fill_n(visited[0], 64, 0); // visited 배열 초기화
    // 상하좌우로 이동하며 바이러스 전파
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        visited[cur.first][cur.second] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (lab[nx][ny] != 0 || visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    // 안전 영역 크기 초기화 및 계산
    int safeAreaCount = n*m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 1 || lab[i][j] == 1) {
                safeAreaCount--;
            }
        }
    }
    return safeAreaCount; // 안전 영역 크기 리턴
}

// 새로 세우는 벽의 위치를 정하는 백트래킹
void backTracking(int n, int idx) {
    // 3개의 벽 위치를 정했으면 안전 영역 크기를 계산
    // 이후 최대 안전 영역 크기와 비교
    if (n == 3) {
        int safeAreaCount = bfs();
        maxSafeArea = max(safeAreaCount, maxSafeArea);
        return;
    }

    // 백트래킹
    for (int i = idx; i < blank.size(); i++) {
        lab[blank[i].first][blank[i].second] = 1;
        backTracking(n + 1, i + 1);
        lab[blank[i].first][blank[i].second] = 0;
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; // 연구소 크기 입력

    // 바이러스 위치 및 빈 공간 위치 push
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) {
                virus.push({i, j});
            }
            else if (lab[i][j] == 0) {
                blank.push_back({i, j});
            }
        }
    }

    // 백트래킹과 bfs를 이용해 최대 안전 영역 크기 계산
    backTracking(0, 0);

    cout << maxSafeArea; // 최대 안전 영역 크기 출력

    return 0;
}
