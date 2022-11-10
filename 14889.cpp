#include <bits/stdc++.h>

using namespace std;

int n;
int table[20][20];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // 인원수 입력
    cin >> n;

    // 능력치 테이블 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }

    // 팀을 나누는 조합을 000111형태로 만듦
    vector<int> team(n, 0);
    fill_n(team.begin(), n/2, 1);
    reverse(team.begin(), team.end());

    // 최소 능력치 차이가 저장될 변수
    int minDiff = INT_MAX;
    
    // next_permutation을 사용하여 모든 팀 조합에 대해
    // 각 팀마다의 능력치 합을 테이블을 참조하여 구하고 최소 차이를 업데이트
    do {
        int startTeam = 0;
        int linkTeam = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (team[i] == 0 && team[j] == 0) {
                    startTeam += table[i][j];
                }
                if (team[i] == 1 && team[j] == 1) {
                    linkTeam += table[i][j];
                }
            }
        }
        int diff = abs(startTeam - linkTeam);
        minDiff = min(minDiff, diff);
    } while (next_permutation(team.begin(), team.end()));

    cout << minDiff;

    return 0;
}
