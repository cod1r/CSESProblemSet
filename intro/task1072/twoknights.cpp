#include <bits/stdc++.h>


using namespace std; 


int main(){
	int n; cin >> n;
	cout << 0 << endl;
	if (n > 1)
		cout << 6 << endl;
	unsigned long long int sub[n];
	sub[0] = 0; sub[1] = 0; sub[2] = 8;
	unsigned long long int sum = 0;
	for (unsigned long long int x = 3; x <= n && n > 2; x++){
		cout << (x * x * (x * x - 1))/2 - sub[x-1] - sum << endl;
		sum += sub[x-1];
		sub[x] = sub[x-1] + 8;
	}
	return 0;
}
