#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m) {
	long long ans = 1;
	while(n) {
		if(n%2) {
			ans = (x * ans) % m;
			n--;
		} else {
			x = (1LL * x * x) % m;
			n /= 2;
		}
	}
	return ans%m;
}