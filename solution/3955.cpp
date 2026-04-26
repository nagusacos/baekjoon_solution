#include <iostream>
using namespace std;

long long ex_gcd(long long a, long long b, long long c = 1) {
	if (a == 0) return 0;
	long long x = ex_gcd(b % a, a, c);
	return (c - b * x) / a;
}

int gcd(int a,int b) {
	if (a > b) swap(a, b);
	for (;a > 0;a %= b)swap(a, b);
	return b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (;T-- > 0;) {
		long long K, C;
		cin >> K >> C;
		if (gcd(K, C) != 1) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		long long Y = ex_gcd(C, K, 1);
		Y = (Y % K + K) % K;
		while (C * Y <= K) Y += K;

		if (Y > 1000000000)
			cout << "IMPOSSIBLE\n";
		else
			cout << Y << "\n";
	}
}