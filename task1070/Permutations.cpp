#include <bits/stdc++.h>


using namespace std; 


int main(){
	int n; cin >> n;
	if (n <= 3 && n > 1) {
		cout << "NO SOLUTION" << endl;
	} else {
		for (int x = 2; x <= n; x+=2){
			cout << x << " ";
		}
		for (int x = 1; x <= n; x+=2){
			cout << x << " ";
		}
	}
	return 0;
}

