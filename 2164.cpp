#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    queue<int> cards;

    int n;
    cin >> n;

    for (int i = 1; i < n+1; i++) {
        cards.push(i);
    }

    
    while (cards.size() != 1) {
        cards.pop();
        if (cards.size() == 1)
            break;
        cards.push(cards.front());
        cards.pop();
    }

    cout << cards.front();

	return 0;
}