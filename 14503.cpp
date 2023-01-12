#include <bits/stdc++.h>

using namespace std;

int board[50][50];
int n, m;
int r, c, d;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void clean() {
    while (true) {
        board[r][c] = -1; // 현재 위치 청소
        int status = 0; // 청소 가능한 방향이 있었는지 체크하는 변수
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4; // 왼쪽으로 90도 회전
            // 회전한 방향으로 한칸 전진했을 때 그 칸이 청소 안된 빈칸인지 체크 
            if (board[r + dx[d]][c + dy[d]] == 0) {
                // 한칸 전진 후 break
                r = r + dx[d];
                c = c + dy[d];
                status = 1;
                break;
            }
        }
        // 청소 가능한 방향이 있었다면 while문 재시작하여 청소
        if (status == 1) continue;
        // 청소 가능한 방향이 없고 한칸 후진했을 때 그 칸이 벽이면 청소 종료
        if (board[r - dx[d]][c - dy[d]] == 1) break;
        // 청소 가능한 방향이 없고 한칸 후진이 가능하면 후진
        if (board[r - dx[d]][c - dy[d]] == -1 || board[r - dx[d]][c - dy[d]] == 0) {
            r = r - dx[d];
            c = c - dy[d];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 각종 변수 입력
    cin >> n >> m;
    cin >> r >> c >> d;

    // 청소 영역 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j]; 
        }
    }

    clean();

    // 청소된 칸 카운트
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == -1) {
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}
