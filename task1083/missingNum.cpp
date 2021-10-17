#include <bits/stdc++.h>


using namespace std; 


int main(){
	unsigned long long int n; cin >> n;
	unsigned long long int sum = 0;
	for (unsigned long long int x = 1; x <= n; x++){
		sum += x;
	}
	--n;
	while(n--){
		unsigned long long int tmp; cin >> tmp;
		sum -= tmp;
	}
	cout << sum;
	return 0;
}
