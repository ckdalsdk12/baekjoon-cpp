#include <bits/stdc++.h>

using namespace std;

int n, w, l;
deque<int> truck; 
int bridge[101];
int completeCount = 0;
int completeTime = 0;

// 현재 다리 위에 있는 트럭의 무게를 계산하기 위한 함수
int calBridgeWeight() {
    int sum = 0;
    for (int i = 0; i < w; i++) {
        sum += bridge[i];
    }
    return sum;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> l;

    // 트럭을 입력받아 deque에 순차적으로 push
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        truck.push_back(input);
    }

    while (true) {
        // 만약 모든 트럭이 도착했다면 break
        if (completeCount == n) break;

        // 다리 이동 시작
        // 다리의 왼쪽 끝에 트럭이 있다면 완료 카운트 ++
        if (bridge[0] != 0) {
            completeCount++;
        }

        // 다리 위 트럭들을 한 칸씩 왼쪽으로 이동
        for (int i = 0; i < w; i++) {
            bridge[i] = bridge[i+1];
        }
        bridge[w-1] = 0;
        // 다리 이동 끝
    
        // 다리 무게 계산
        int bridgeWeight = calBridgeWeight();
        
        // 다리를 건너지 않은 트럭이 있다면 다음 순서 후보로 올림
        int nextTruck = 0;
        if (!truck.empty()) {
            nextTruck = truck.front();
            
            // 후보를 다리에 올려도 다리 무게가 초과되지 않는다면 트럭을 다리에 올림
            if (bridgeWeight + nextTruck <= l) {
            truck.pop_front();
            bridge[w-1] = nextTruck;
            }
        }

        // 걸린 시간 ++
        completeTime++;
    }

    cout << completeTime << "\n";

    return 0;
}