#include <iostream>
using namespace std;
typedef unsigned long long integer;

integer pow_mod(integer N, integer K, integer M) {
	integer val = 1;
	N %= M;
	for (;K > 0;K >>= 1) {
		if (K & 1)
			val = (val * N) % M;
		N = (N * N) % M;
	}
	return val;
}

bool miller_rabin(integer N, integer p) {
	if (!(N & 1))
		return false;
	integer d = N - 1;
	int s = 0;
	for (;!(d & 1);d >>= 1)s++;

	integer x = pow_mod(p, d, N);
	if (x == 1 || x == N - 1)
		return true;
	for (int r = 0;r < s;r++) {
		x = (x * x) % N;
		if (x == N - 1)
			return true;
	}
	return false;
}

bool is_prime(integer N) {
	if (N <= 1 || !(N & 1))
		return false;
	integer prime[3] = { 2,3,61 };
	for (int i = 0;i < 3;i++) {
		if (N == prime[i])
			return true;
		if (!miller_rabin(N, prime[i]))
			return false;
	}
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int N;
	cin >> N;
	int sum = 0;
	for (;N-- > 0;) {
		integer S;
		cin >> S;
		if (is_prime(2 * S + 1))
			sum++;
	}
	cout << sum;
}