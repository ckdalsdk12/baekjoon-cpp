#include <bits/stdc++.h>

using namespace std;

string wheel[4];
int k;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // 톱니바퀴 입력
    for (int i = 0; i < 4; i++) {
        cin >> wheel[i];
    }

    cin >> k;

    // 총 k번 회전
    while (k--) {
        int wheelNum;
        int dir;
        cin >> wheelNum >> dir;
        // 톱니바퀴 번호 입력은 1~4지만 인덱스는 0~3이므로 -1 처리
        wheelNum = wheelNum-1;
        
        // 각 톱니바퀴의 회전 여부 / 방향을 나타내는 값을 저장할 배열
        int dirs[4];
        fill_n(dirs, 4, 0);
        
        // 입력받은 톱니바퀴 하나의 번호와 방향을 저장
        dirs[wheelNum] = dir;

        // 입력받은 톱니바퀴로부터 왼쪽으로
        // 왼쪽 끝 톱니바퀴 또는 회전이 되지 않을 때까지 회전 방향 탐색
        int leftWheel = wheelNum;
        while (true) {
            if (leftWheel <= 0 || wheel[leftWheel][6] == wheel[leftWheel-1][2]) {
                break;
            }
            dirs[leftWheel-1] = -dirs[leftWheel];
            leftWheel--;
        }

        // 입력받은 톱니바퀴로부터 오른쪽으로
        // 오른쪽 끝 톱니바퀴 또는 회전이 되지 않을 때까지 회전 방향 탐색
        int rightWheel = wheelNum;
        while (true) {
            if (rightWheel >= 3 || wheel[rightWheel][2] == wheel[rightWheel+1][6]) {
                break;
            }
            dirs[rightWheel+1] = -dirs[rightWheel];
            rightWheel++;
        }

        // 탐색한 회전 방향으로 실제적으로 톱니바퀴 회전
        for (int i = 0; i < 4; i++) {
            // 시계 방향으로 회전 (오른쪽으로 이동)
            if (dirs[i] == 1) {
                rotate(wheel[i].begin(), wheel[i].end()-1, wheel[i].end());
            }
            // 시계 반대 방향으로 회전 (왼쪽으로 이동)
            else if (dirs[i] == -1) {
                rotate(wheel[i].begin(), wheel[i].begin()+1, wheel[i].end());
            }
        }
    }

    // 회전이 완료된 톱니바퀴로부터 점수 찾기
    int score = 0;
    for (int i = 0; i < 4; i++) {
        // cout << wheel[i] << "\n";
        if (wheel[i][0] == '1') {
            score += int(pow(2, i));
        }
    }
    cout << score;

    return 0;
}
