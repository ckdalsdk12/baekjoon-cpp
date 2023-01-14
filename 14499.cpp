#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, k;
int board[20][20]; // 지도
int dice[6] = {0, 0, 0, 0, 0, 0}; // 위=0, 왼=1, 앞=2, 오른=3, 뒤=4, 아래=5

void moveDice(int dir) {
    if (dir == 1) { // 동쪽
        if (y + 1 < 0 || y + 1 >= m) return; // 지도의 바깥으로 이동하려는 경우 종료
        y = y + 1;
        int tmp = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = tmp;
    }
    else if (dir == 2) { // 서쪽
        if (y - 1 < 0 || y - 1 >= m) return; // 지도의 바깥으로 이동하려는 경우 종료
        y = y - 1;
        int tmp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[1];
        dice[1] = tmp;
    }
    else if (dir == 3) { // 북쪽
        if (x - 1 < 0 || x - 1 >= n) return; // 지도의 바깥으로 이동하려는 경우 종료
        x = x - 1;
        int tmp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[2];
        dice[2] = tmp;
    }
    else if (dir == 4) { // 남쪽
        if (x + 1 < 0 || x + 1 >= n) return; // 지도의 바깥으로 이동하려는 경우 종료
        x = x + 1;
        int tmp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[4];
        dice[4] = tmp;
    }

    // 칸의 값이 0일때 주사위 값 복사
    if (board[x][y] == 0) {
        board[x][y] = dice[5];
    }
    // 칸의 값이 0이 아닐때 0으로 초기화 및 주사위에 칸의 값 복사
    else if (board[x][y] != 0) {
        dice[5] = board[x][y];
        board[x][y] = 0;
    }

    // 주사위 윗 면 출력
    cout << dice[0] << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 각종 값 입력
    cin >> n >> m >> x >> y >> k;
    
    // 지도 칸 값 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // k번 이동 명령
    while(k--) {
        int dir;
        cin >> dir;
        moveDice(dir);
    }

    return 0;
}
