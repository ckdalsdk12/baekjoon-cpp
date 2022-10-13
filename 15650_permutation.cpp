#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, m;
    cin >> n >> m;

	for (int i = 0; i < n; i++) {
		if (i < m) {
			arr.push_back(0);
		}
		else arr.push_back(1);
	}

	do {
		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) {
				cout << i+1 << " ";
			}
		}
		cout << "\n";
	} while (next_permutation(arr.begin(), arr.end()));

	return 0;
}