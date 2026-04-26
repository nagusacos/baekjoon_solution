#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef unsigned long long integer;

integer gcd(integer A, integer B) {
	if (A > B) swap(A, B);//A<=B
	for (;A > 0;A %= B)swap(A, B);
	return B;
}

integer pow_mod(integer N, integer K, integer M) {
	integer val = 1;
	for (;K > 0;K >>= 1) {
		if (K & 1)
			val = (integer)(((__int128)val * N) % M);
		N = (integer)(((__int128)N * N) % M);
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
		x = (integer)(((__int128)x * x) % N);
		if (x == N - 1)
			return true;
	}
	return false;
}

bool is_prime(integer N) {
	integer prime[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
	for (int i = 0;i < 9;i++) {
		if (N == prime[i])
			return true;
		if (!miller_rabin(N, prime[i]))
			return false;
	}
	return true;
}

integer pollard_rho(integer N) {
	integer x = 2;
	integer y = x;
	integer c = 1;
	integer d = 1;
	for (;d == 1;) {
		x = (integer)(((__int128)x * x) % N + c);
		if (x >= N)x -= N;
		y = (integer)(((__int128)y * y) % N + c);
		if (y >= N)y -= N;
		y = (integer)(((__int128)y * y) % N + c);
		if (y >= N)y -= N;
		d = gcd((x > y ? x - y : y - x), N);
		if (d == N) {
			d = 1;
			x++;
			y = x;
			c++;
		}
	}
	return d;
}

vector<integer> factorization(integer N) {
	vector<integer> factor;
	integer Q[5000];
	int q = 0;
	int idx = 0;
	Q[q++] = N;
	for (;idx < q;idx++) {
		integer n = Q[idx];

		if (n <= 1)//1
			continue;
		if (is_prime(n)) {//prime
			factor.push_back(n);
			continue;
		}

		integer d = 0;
		if (!(n & 1)) d = 2;//even
		else d = pollard_rho(n);//odd
		n /= d;
		Q[q++] = d;
		Q[q++] = n;
	}
	return factor;
}
bool is_squr(integer N) {
	integer sq = round(sqrtl(N));
	return (sq * sq == N);
}
bool legendre(integer N) {
	while (N % 4 == 0) {
		N /= 4;
	}
	if (N % 8 == 7)
		return true;
	return false;
}
bool fermat(integer N) {
	vector<integer> S = factorization(N);
	sort(S.begin(), S.end());
	for (int i = 0; i < S.size(); ) {
		integer p = S[i];
		int count = 0;
		while (i < S.size() && S[i] == p) {
			count++;
			i++;
		}
		if (p % 4 == 3 && count % 2 != 0)
			return false;
	}
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	integer N;
	cin >> N;
	if (is_squr(N))
		cout << "1";
	else if (legendre(N))
		cout << "4";
	else if (fermat(N))
		cout << "2";
	else
		cout << "3";
}
