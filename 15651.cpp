#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[7];

void nm(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        arr[k] = i;
        nm(k+1);
    }
}

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

    nm(0);

	return 0;
}