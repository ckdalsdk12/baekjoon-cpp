#include <bits/stdc++.h>

using namespace std;

int board[20][20]; // 원본 보드
int processingBoard[20][20]; // 이동을 진행하고 있는 보드 
int n;

void rotate() {
    int temp[20][20];
    // temp보드에 진행되고 있던 보드 복사
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = processingBoard[i][j];
        }
    }
    // temp보드를 시계방향으로 90도 회전시켜 진행되고 있던 보드에 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            processingBoard[i][j] = temp[n-1-j][i];
        }
    }
}

void move(int dir) {
    // dir만큼 회전
    while(dir--) {
        rotate();
    }
    // 행 또는 열 기준으로 한 라인씩 처리하여 보드 값을 특정 방향으로 이동
    for (int i = 0; i < n; i++) {
        int processingLine[20];
        fill_n(processingLine, 20, 0);
        int index = 0;
        for (int j = 0; j < n; j++) {
            // 진행중인 보드의 칸이 빈칸이라면 continue;
            if (processingBoard[i][j] == 0) continue;
            // 진행중인 라인의 index칸이 빈칸이라면 그 칸에 보드의 칸 값 저장
            if (processingLine[index] == 0) {
                processingLine[index] = processingBoard[i][j];
            }
            // 진행중인 라인의 index칸의 값이 보드의 칸 값과 같다면
            // index칸 값 2배 후 index 1 증가
            else if (processingLine[index] == processingBoard[i][j]) {
                processingLine[index] *= 2;
                index++;
            }
            // 만약 두 값이 같은 값이 아니라면
            // index 1 증가 후 진행중인 라인의 index칸에 보드의 칸 값 저장
            else {
                index++;
                processingLine[index] = processingBoard[i][j];
            }
        }
        // 이동 처리 완료된 라인을 보드에 적용
        for (int j = 0; j < n; j++) {
            processingBoard[i][j] = processingLine[j];
        }
    }
}

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // 보드의 크기와 값 입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    // 모든 가능성에 대해 탐색. 가장 큰 블록 값 찾기.
    int maxValue = 0;
    for (int possibility = 0; possibility < 1024; possibility++) {
        // board를 processingBoard에 복사
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                processingBoard[i][j] = board[i][j];
            }
        }
        // 해당 가능성에 맞게 회전 및 처리
        int temp = possibility;
        for (int i = 0; i < 5; i++) {
            int dir = temp % 4;
            temp /= 4;
            move(dir);
        }
        // 최대 값 구하기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxValue = max(maxValue, processingBoard[i][j]);
            }
        }
    }

    cout << maxValue;

    return 0;
}