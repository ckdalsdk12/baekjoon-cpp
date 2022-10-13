#include <bits/stdc++.h>

using namespace std;

int N;
int maxCrashed = 0;
int crashed = 0;
pair<int, int> egg[10];

void crashEgg(int k) {
    if (k == N) {
        maxCrashed = max(maxCrashed, crashed);
        return;
    }

    if (egg[k].first <= 0 or crashed == N-1) {
        crashEgg(k+1);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (i == k or egg[i].first <= 0)
            continue;
            
        egg[k].first -= egg[i].second;
        egg[i].first -= egg[k].second;
        if (egg[k].first <= 0)
            crashed++;
        if (egg[i].first <= 0)
            crashed++;

        crashEgg(k+1);

        if (egg[k].first <= 0)
            crashed--;
        if (egg[i].first <= 0)
            crashed--;
        egg[k].first += egg[i].second;
        egg[i].first += egg[k].second;
    }
}

int main(int argc, char** argv) {
	
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> egg[i].first >> egg[i].second;
    }

    crashEgg(0);

    cout << maxCrashed;

	return 0;
}