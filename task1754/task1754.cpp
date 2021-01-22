#include <bits/stdc++.h>
using namespace std;

/*
You have two coin piles containing a and b coins. 
On each move, you can either remove one coin from the left pile and two coins from the right pile, 
or two coins from the left pile and one coin from the right pile.

Your task is to efficiently find out if you can empty both the piles.
*/

int main(){
	int tt; cin >> tt;
	while(tt--){
		int a, b; cin >> a >> b;
		if (a > b){
			int t = a;
			a-=2*(a-b);
			b-=(t-b);
			if (a % 3 != 0 || a < 0 || b < 0|| (a <= 0 && b > 0) || (a > 0 && b <= 0)){
				cout << "NO" << endl;
			} else {
				cout << "YES" << endl;
			}
		} else if (b>a){
			int t = b;
			b-=2*(b-a);
			a-=(t-a);
			if (a%3!=0 || a < 0 || b < 0 || (a <= 0 && b > 0) || (a > 0 && b <= 0)){
				cout << "NO" << endl;
			} else {
				cout << "YES" << endl;
			}
		} else if (a%3==0 && a > 0 && b > 0 || (a==0 && b == 0)){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}