#include <bits/stdc++.h>

using namespace std;

int arr[15];
int nums[15];
int history[15];

void lotto(int k, int n) {
    if (k == 6) {
        bool check = true;
        int prev = 0;
        
        for (int i = 0; i < 6; i++) {
            if (prev > nums[arr[i]]) {
                check = false;
            }
            prev = nums[arr[i]];
        }

        if (check) {
            for (int i = 0; i < 6; i++) {
                cout << nums[arr[i]] << " ";
            }
            cout << "\n";
        }
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (history[i] == 0) {
            arr[k] = i;
            history[i] = 1;
            lotto(k+1, n);
            arr[k] = 0;
            history[i] = 0;
        }
    }
}

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    while (true) {
        fill_n(arr, 15, 0);
        fill_n(nums, 15, 0);
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        lotto(0, n);
        
        cout << "\n";
    }

	return 0;
}