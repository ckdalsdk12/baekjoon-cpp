#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int nums[10];

void nm(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << nums[arr[i]] << " ";
        }
        cout << "\n";
        return;
    }

    int start = 0;
    if (k != 0) {
        start = arr[k-1];
    }

    for (int i = start; i < n; i++) {
        arr[k] = i;
        nm(k+1);
        arr[k] = 0;
    }
}

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums+n);

    nm(0);

	return 0;
}