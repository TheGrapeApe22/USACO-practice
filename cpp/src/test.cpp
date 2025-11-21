#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll sum = 0;
	for (ll i = 1; i <= 825000; i++) {
		ll sq = i*i;
		if (sq % 2 == 1) {
			sum += sq;
		}
	}
	cout << sum << '\n';
}
