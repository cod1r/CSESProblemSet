#include <bits/stdc++.h>


using namespace std; 


int main(){
    unsigned long long int n; cin >> n;
    while(n >= 1){
		cout << n << " ";
		if (n==1) break;
		if (n % 2 == 0) {n/=2;}
		else {n*=3;n++;}
	}

	return 0;
}
