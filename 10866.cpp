#include <bits/stdc++.h>

using namespace std;

int main(void) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;
	deque<int> deq;
	
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		
		if (str == "push_front")
		{
			int pushint = 0;
			cin >> pushint;
			deq.push_front(pushint);
		}
		
		else if (str == "push_back")
		{
			int pushint = 0;
			cin >> pushint;
			deq.push_back(pushint);
		}
		
		else if (str == "pop_front")
		{
			if (deq.empty() == false)
			{
				cout << deq.front() << "\n";
				deq.pop_front();
			}
			else cout << -1 << "\n";
		}
		
		else if (str == "pop_back")
		{
			if (deq.empty() == false)
			{
				cout << deq.back() << "\n";
				deq.pop_back();
			}
			else cout << -1 << "\n";
		}
		
		else if (str == "size")
		{
			cout << deq.size() << "\n";
		}
		
		else if (str == "empty")
		{
			if (deq.empty() == true)
				cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		
		else if (str == "front")
		{
			if (deq.empty() == false)
				cout << deq.front() << "\n";
			else cout << -1 << "\n";
		}
		
		else if (str == "back")
		{
			if (deq.empty() == false)
				cout << deq.back() << "\n";
			else cout << -1 << "\n";
		}
	}
	
	return 0;
}