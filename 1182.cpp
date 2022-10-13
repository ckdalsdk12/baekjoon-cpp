#include <bits/stdc++.h>

using namespace std;

int n, s, cnt;
int arr[20];

void check(int k, int sum) {
    if (k == n) {
        if (sum == s) {
            cnt++;
        }
        return;
    }
    check(k+1, sum);
    check(k+1, sum+arr[k]);
}

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    check(0, 0);
    if (s == 0) {
        cnt--;
    }
    cout << cnt;

	return 0;
}