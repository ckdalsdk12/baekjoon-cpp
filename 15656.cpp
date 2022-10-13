#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[8];
int nums[10];

void nm(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << nums[arr[i]] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = 0; i < n; i++) {
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
        int num;
        cin >> num;
        nums[i] = num;
    }

    sort(nums, nums+n);

    nm(0);

	return 0;
}