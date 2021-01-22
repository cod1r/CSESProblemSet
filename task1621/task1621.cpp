#include <bits/stdc++.h>
using namespace std;

int main(){
	set<int> s;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		if (s.count(t) == 0)
			s.insert(t);
	}
	cout << s.size() << endl;
	return 0;
}