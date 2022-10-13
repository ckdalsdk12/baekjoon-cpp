#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    deque<int> deq;
    int sumCount = 0;
    int n, m;
    cin >> n >> m;

    for (int i = 1; i < n+1; i++) {
        deq.push_back(i);
    }
	
    for (int i = 0; i < m; i++) {
        int pick;
        cin >> pick;
        // int countL = 0;
        // int countR = 0;
        int count = 0;
        int size = deq.size();
        while (1) {
            if (!deq.empty()) {
                if (deq.front() == pick) {
                    deq.pop_front();
                    if (size / 2 < count)
                        count = size - count;
                    sumCount += count;
                    break;
                }
                else {
                    deq.push_back(deq.front());
                    deq.pop_front();
                    count++;
                }
            }
        }
    }

    cout << sumCount;

	return 0;
}