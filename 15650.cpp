#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[8];
int histroy[9];

void nm(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int t = 1;
    if (k != 0) t = arr[k-1] + 1;
    for (int i = t; i <= n; i++) {
        if (histroy[i] == 0) {
            arr[k] = i;
            histroy[i] = 1;
            nm(k+1);
            arr[k] = 0;
            histroy[i] = 0;
        }
    }
}

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

    nm(0);

	return 0;
}