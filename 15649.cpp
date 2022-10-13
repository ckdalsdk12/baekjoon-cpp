#include <bits/stdc++.h>

using namespace std;

int arr[8];
int used[9];
int n, m;

void bt(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i] == 0) {
            arr[k] = i;
            used[i] = 1;
            bt(k+1);
            arr[k] = 0;
            used[i] = 0;
        }
    }
}

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

    bt(0);

	return 0;
}