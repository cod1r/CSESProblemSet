#include <bits/stdc++.h>
#define ll long long


using namespace std; 


int main(){
	int n; cin >> n;
	unsigned ll int m = 2;
	for (int i = 0 ; i < n-1; i ++){
		m *= 2;
		m %= 1000000007;
	}
	cout << m << endl;
	return 0;
}
