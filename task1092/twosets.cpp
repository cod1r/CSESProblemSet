#include <bits/stdc++.h>

#define ll long long
using namespace std; 


int main(){
	int n; cin >> n;
	unsigned long long int sum = 0; for (int x = 1; x <= n; x++) sum += x;
	if (sum % 2 == 0) {
		cout << "YES" << endl;
		vector<unsigned ll int> arr(n); for (int i = 1; i <= n; i++) arr[i-1] = i;
		set<unsigned ll int> first, second;
		unsigned long long int sum2 = 0;
		for (int i = 0; i < n; i++){
			sum2 += arr[i];
			first.insert(arr[i]);
			if (sum2 > sum/2) break;
		}
		for (int i = 0; i < n; i++){
			if (arr[i] == sum2 - sum/2) first.erase(arr[i]);
		}
		for (int i = 0; i < n; ++i){
			if (first.find(arr[i]) == first.end()) second.insert(arr[i]);
		}
		cout << first.size() << endl;
		for (int i : first) cout << i << " ";
		cout << endl;
		cout << second.size() << endl;
		for (int i : second) cout << i << " ";
	} else {
		cout << "NO" << endl;
	}
	return 0;
}

