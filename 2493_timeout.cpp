#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    stack<int> towers;
    stack<int> where;
    vector<int> towersVector;
    int cur;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tower;
        cin >> tower;
        towers.push(tower);
        towersVector.push_back(tower);
    }

    while (!towers.empty()) {
        cur = towers.top();
        towers.pop();
        int count = towers.size();
        while (count != 0) {
            if (towersVector[count-1] >= cur) {
                where.push(count);
                break;
            }
            count--;
        }
        if (count == 0) {
            where.push(0);
        }
    }

    while (!where.empty()) {
        cout << where.top() << " ";
        where.pop();
    }

	return 0;
}