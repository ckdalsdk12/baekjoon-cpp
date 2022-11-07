#include <bits/stdc++.h>

using namespace std;

int n, m;
int city[50][50];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // 도시의 크기, 살아남을 치킨집의 개수 및 도시 좌표마다의 정보 입력.
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            // 1이면 집
            if (city[i][j] == 1) {
                house.push_back(make_pair(i, j));
            }
            // 2이면 치킨집
            if (city[i][j] == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    
    // 살아남을 치킨집을 나타내기 위한 조합
    vector<int> combination(chicken.size(), 0);
    fill_n(combination.begin(), m, 1);
    reverse(combination.begin(), combination.end());

    // 도시의 치킨거리의 최소값이 저장될 변수
    int minDistance = INT_MAX;

    // next_permutation을 사용해 모든 조합에 대해 반복.
    // 각 집마다 각 치킨집에 대해 치킨거리를 구하고 
    // 최소의 치킨거리를 도시의 치킨거리에 더한다.
    do {
        int chickenDistance = 0;
        for (pair<int, int> h : house) {
            int eachDistance = INT_MAX;
            for (int i = 0; i < chicken.size(); i++) {
                if (combination[i] == 0) continue;
                eachDistance = min(eachDistance,
                abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
            }
            chickenDistance += eachDistance;
        }
        minDistance = min(minDistance, chickenDistance);
    } while (next_permutation(combination.begin(), combination.end()));

    cout << minDistance;

    return 0;
}