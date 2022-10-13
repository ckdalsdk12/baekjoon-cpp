#include <bits/stdc++.h>

using namespace std;

long long multiple(int a, int b, int c) {
	if (b == 1) return a % c;
	long long mul = multiple(a, b/2, c);
	mul = mul * mul % c;
	if (b % 2 == 0) return mul;
	if (b % 2 == 1) return mul * a % c;
}

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	
	cout << multiple(a, b, c);

	return 0;
}