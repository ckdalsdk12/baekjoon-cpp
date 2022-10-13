#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int nums[10];
int history[10];

void nm(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << nums[arr[i]] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = 0;
    
    for (int i = 0; i < n; i++) {
        if (history[i] == 0 && prev != nums[i]) {
            arr[k] = i;
            history[i] = 1;
            prev = nums[arr[k]];
            nm(k+1);
            arr[k] = 0;
            history[i] = 0;
        }
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