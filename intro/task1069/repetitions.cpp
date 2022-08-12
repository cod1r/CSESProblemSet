#include <bits/stdc++.h>


using namespace std; 


int main(){

	string temp;
	cin >> temp;
	int start = 0, end = 1, rep = 1;
	while(end < temp.size()){
		if (temp[end] == temp[start]){
			end++;
		} else {
			if (end - start > rep) rep = end-start;
			start = end;
		}
	}
	if (end - start > rep) rep = end-start;
	cout << rep << endl;
	return 0;
}
