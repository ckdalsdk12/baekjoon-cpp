#include<bits/stdc++.h>

using namespace std;

int a[1000001];
int b[1000001];
int c[2000002];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int idxA = 0, idxB = 0;
    
    for (int i = 0; i < n+m; i++) {
        if (idxB == m) {
            c[i] = a[idxA];
            idxA++;
        }
        else if (idxA == n) {
            c[i] = b[idxB];
            idxB++;
        }
        else if (a[idxA] <= b[idxB]) {
            c[i] = a[idxA];
            idxA++;
        }
        else if (b[idxB] <= a[idxA]) {
            c[i] = b[idxB];
            idxB++;
        }
    }

    for (int i = 0; i < n+m; i++) {
        cout << c[i] << " ";
    }

    return 0;
}
