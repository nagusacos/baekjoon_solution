#include <iostream>
using namespace std;
#define MOD 1000000007

long long power(long long A, int n) {
	long long K = 1;
	for (int i = 0;i <= 30;i++) {
		if (n & (1 << i))
			K = (K * A) % MOD;
		A = (A * A) % MOD;
	}
	return K;
}

long long combination(int n,int k) {
	k = min(k, n - k);

	long long E = 1, F = 1;
	for (int i = 1;i <= k;i++) {
		E = (E * i) % MOD;
		F = (F * (n - k + i)) % MOD;
	}
	return (F * power(E, MOD - 2)) % MOD;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	cout << combination(N, K);

	return 0;
}