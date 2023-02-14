#include<bits/stdc++.h>

using namespace std;

int cnt[2000001];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cnt[num+1000000]++;
    }

    for (int i = 0; i < 2000001; i++) {
        if (cnt[i] == 0) continue;
        while(cnt[i]--) {
            cout << i-1000000 << "\n";
        }
    }

    return 0;
}
