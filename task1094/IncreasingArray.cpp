#include <bits/stdc++.h>


using namespace std; 


int main(){
	int size; cin >> size;
	long int first; cin >> first; size--;
	unsigned long long int turns = 0;
	while(size--){
		long int tmp; cin >> tmp;
		if (tmp < first){
			turns += (tmp-first)*-1;
			first = tmp+(first-tmp);
		} else {
			first = tmp;
		}
	}
	cout << turns << endl;
	return 0;
}
