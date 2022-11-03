#include <bits/stdc++.h>

using namespace std;

int notebook[40][40];
int stickerPaper[10][10];
int n, m, k;
int r, c;

// 노트북의 x, y 좌표를 기준으로 붙일 수 있는지 확인 및 붙임
bool checkAndStick(int x, int y) {
    // 이미 스티커가 있는 좌표면 false 반환
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (notebook[x+i][y+j] == 1 && stickerPaper[i][j] == 1) {
                return false;
            }
        }
    }
    // 스티커를 붙일 수 있는 좌표면 스티커 붙임
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (stickerPaper[i][j] == 1) {
                notebook[x+i][y+j] = 1;
            }
        }
    }
    return true;
}

// 스티커가 붙어있는 종이를 회전시킴
void rotateStickerPaper() {
    // tempPaper에 임시로 복사
    int tempStickerPaper[10][10];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tempStickerPaper[i][j] = stickerPaper[i][j];
        }
    }
    // 회전
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            stickerPaper[i][j] = tempStickerPaper[r-1-j][i];
        }
    }
    swap(r, c);
}

int main(void) {

    ios::sync_with_stdio(0);
	cin.tie(0);

    // 기초 정보 입력
    cin >> n >> m >> k;

    // k개의 스티커 종이에 대해 반복
    while(k--) {
        // 스티커 좌표 입력
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> stickerPaper[i][j];
            }
        }
        // 스티커 부착 가능성 체크 및 부착 및 회전
        for (int rotation = 0; rotation < 4; rotation++) {
            bool breakPoint = false;
            for (int i = 0; i <= n-r; i++) {
                if (breakPoint == true) break;
                for (int j = 0; j <= m-c; j++) {
                    if (checkAndStick(i, j) == true) {
                        breakPoint = true;
                        break;
                    }
                }
            }
            if (breakPoint == true) break;
            rotateStickerPaper();
        }
    }

    // 스티커가 붙여진 공간 카운트 및 출력
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (notebook[i][j] == 1)
                count++;
        }
    }
    cout << count << "\n";

	return 0;
}