// taken from 3320 hw chaintenges
#include <bits/stdc++.h>

#define ll long long
#define MIN_GLOBAL LLONG_MIN
#define MAX_GLOBAL LLONG_MAX

ll r(std::vector<ll>& arr, std::vector<ll> groups, int index, ll max_val, ll min_val) {
	if (index >= arr.size() || min_val < max_val) {
		return max_val;
	}
	ll a = MAX_GLOBAL;
	ll t = MIN_GLOBAL;
	for (int i = 0; i < (int)groups.size(); i++) {
		std::vector<ll> copy = groups;
		copy[i] += arr[index];
		t = std::max(max_val, copy[i]);
		a = std::min(a, min_val);
		a = std::min(a, r(arr, copy, index + 1, t, a));
	}
	return a;
}

int main() {
	ll n, k = 2;
	std::cin >> n;
	std::vector<ll> arr(n);
	ll total = 0;
	for (ll& i : arr) {
		std::cin >> i;
		total += i;
	}
	ll ans = r(arr, std::vector<ll>(k, 0), 0, MIN_GLOBAL, MAX_GLOBAL);
	std::cout << abs(total - 2*ans) << std::endl;
	return 0;
}

