#include <bits/stdc++.h>

using namespace std;

int n, cnt;
int check1[15];
int check2[30];
int check3[30];

void queen(int k) {
    if (k == n) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (check1[i] == 0 && check2[k+i] == 0 && check3[k-i+n-1] == 0) {
            check1[i] = 1;
            check2[k+i] = 1;
            check3[k-i+n-1] = 1;
            queen(k+1);
            check1[i] = 0;
            check2[k+i] = 0;
            check3[k-i+n-1] = 0;
        }
    }
}

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;

    queen(0);

    cout << cnt;

	return 0;
}