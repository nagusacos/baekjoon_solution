#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long integer;

integer gcd(integer A,integer B) {
	if (A > B) swap(A, B);//A<=B
	for (;A > 0;A %= B)swap(A, B);
	return B;
}

integer mult_mod(integer A, integer B, integer M) {//A,B<M
	integer val = 0;
	for (;A > 0;A >>= 1) {
		if (A & 1) {
			val += B;
			if (val >= M) val -= M;
		}
		B += B;
		if (B >= M)B -= M;
	}
	return val;
}

integer pow_mod(integer N, integer K, integer M) {
	integer val = 1;
	for (;K > 0;K >>= 1) {
		if (K & 1)
			val = mult_mod(val, N, M);
		N = mult_mod(N, N, M);
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
		x = mult_mod(x, x, N);
		if (x == N - 1)
			return true;
	}
	return false;
}

bool is_prime(integer N) {
	integer prime[12] = { 2,3,5,7,11,13,17,19,23,29,31,37 };
	int L = 1;
	if (2000 < N) L = 4;
	if (3000000000 < N)L = 12;
	for (int i = 0;i < L;i++) {
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
		x = mult_mod(x, x, N) + c;
		if (x >= N)x -= N;
		y = mult_mod(y, y, N) + c;
		if (y >= N)y -= N;
		y = mult_mod(y, y, N) + c;
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
	for (;idx<q;idx++) {
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	
	integer N;
	cin >> N;
	vector<integer> S = factorization(N);
	sort(S.begin(),S.end());
	for (const integer& s : S)
		cout << s << "\n";
}
