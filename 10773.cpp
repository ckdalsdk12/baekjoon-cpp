#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    int k;
    cin >> k;

    stack<int> s;

    for (int i = 0; i < k; i++) {
        int money;
        cin >> money;
        if (money == 0) {
            if (!s.empty())
                s.pop();
        }
        else
            s.push(money);
    }

    int sumMoney = 0;

    while (!s.empty()) {
        sumMoney += s.top();
        s.pop();
    }

    cout << sumMoney;

	return 0;
}