#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, k;
    cin >> n >> k;

    list<int> circle;

    for (int i = 1; i < n+1; i++) {
        circle.push_back(i);
    }

    list<int>::iterator it = circle.begin();

    cout << "<";

    while (!circle.empty()) {
        for (int i = 0; i < k-1; i++) {
            if (it == --circle.end()) {
                it = circle.begin();
            }
            else it++;
        }
        cout << *it;
        it = circle.erase(it);
        if (it == circle.end()) {
            it = circle.begin();
        }
        if (circle.empty()) {
            cout << ">";
        }
        else cout << ", ";
    }

	return 0;
}