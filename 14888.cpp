#include <bits/stdc++.h>

using namespace std;

int n; // 수의 개수
int num[12]; // n개의 수를 입력받아 저장할 배열
int symbol[4]; // 각 연산자의 개수(조건)을 입력받아 저장할 배열
int symbolList[12]; // 연산자를 순차적으로 나열할 배열
int maxValue = INT_MIN;
int minValue = INT_MAX;

// 백트래킹으로 모든 경우의 수를 체크
void backTracking(int now) {
    // 수식의 끝에 도달하면 해당 경우의 수식을 연산하고 최대, 최소 갱신
    if (now == n) {
        int value = num[0];
        for (int i = 1; i < n; i++) {
            if (symbolList[i] == 0) {
                value += num[i];
            }
            else if (symbolList[i] == 1) {
                value -= num[i];
            }
            else if (symbolList[i] == 2) {
                value *= num[i];
            }
            else if (symbolList[i] == 3) {
                value /= num[i];
            }
        }
        maxValue = max(maxValue, value);
        minValue = min(minValue, value);

        // 디버깅 용
        // for (int i = 1; i < n; i++) {
        //     cout << symbolList[i] << " ";
        // }
        // cout << "\n";
    }

    // 수식의 끝이 아니라면 각 연산자의 개수를 기반으로 연산자를 순차적으로 나열
    for (int i = 0; i < 4; i++) {
        if (symbol[i] == 0) continue;
        if (symbol[i] > 0) {
            symbol[i]--;
            symbolList[now] = i;
            backTracking(now+1);
            symbol[i]++;
            symbolList[now] = 0;
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> symbol[i];
    }

    // 첫 번째 연산자부터 백트래킹 시작
    backTracking(1);

    cout << maxValue << "\n";
    cout << minValue << "\n";

    return 0;
}
