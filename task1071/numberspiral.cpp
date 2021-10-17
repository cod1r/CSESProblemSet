#include <bits/stdc++.h>


using namespace std; 


int main(){
	int n; cin >> n;
	while(n--){
		unsigned long long int y, x; cin >> y >> x;
		if (y == 1 && x == 1) {
			cout << 1 << endl;
			continue;
		}
		if (y > x){
			unsigned long long int corner = y*y-(y-1);
			if (y % 2 == 0){
				corner += (y-x);
			} else {
				corner -= (y-x);
			}
			cout << corner << endl;
		} else {
			unsigned long long int corner = x*x-(x-1);
			if (x % 2 == 0){
				corner -= (x-y);
			} else {
				corner += (x-y);
			}
			cout << corner << endl;
		}
	}
	return 0;
}
