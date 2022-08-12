#include <string>
#include <iostream>
using namespace std;

/*
Assigning a house that just fits the size requirements (x - k, x + k) might not be the best if we are
trying to maximize the amount of people that get houses.


Example case:
3 4 2
10 12 14
11 12 10 9

10 -> 12
12 -> 11
Only two people get apartments if the person that wants a size 10 chooses an
apartment of size 12

If the size-10 person chose 9 then all three people would get apartments

Choosing the apartment size closest to the desired size wouldn't give the maximized answer
either because of this case:

3 4 2
10 12 14
9 10 12

if size-10 person chose 10 and size-12 person chose 12 then the result would be 2
but if size-10 person chose 9 and size-12 person chose 10 then the result would be 3

 */
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	int des[n];
	int siz[m];
	for(int& i: des)
		cin >> i;
	for(int& i: siz)
		cin >> i;
	return 0;
}
