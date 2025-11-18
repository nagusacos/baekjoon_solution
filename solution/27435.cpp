#include <iostream>
using namespace std;

#define mod 998244353

long long V[5] = { 2,2,1,1,1 };
long long** M = new long long* [5];
long long init[5][5] = {
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 1, 0}
};

long long temp[5][5];
void mult(long long** C, long long** A, long long** B) {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			long long sum = 0;
			for (int k = 0; k < 5;k++)
				sum += A[i][k] * B[k][j];
			temp[i][j] = sum % mod;
		}
	}
	for (int i = 0;i < 5;i++)
		for (int j = 0;j < 5;j++)
			C[i][j] = temp[i][j];
}

long long** pow(long long** A,long long N) {
	if (N <= 1)
		return A;
	long long n = N >> 1;
	long long** F = pow(A, n);
	long long** R = new long long* [5];
	for (int i = 0;i < 5;i++)
		R[i] = new long long[5];

	mult(R, F, F);

	if (N % 2 != 0)
		mult(R, M, R);

	return R;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	for (int i = 0;i < 5;i++) {
		M[i] = new long long[5];
		for (int j = 0;j < 5;j++)
			M[i][j] = init[i][j];
	}

	int T;
	cin >> T;
	for (;T-- > 0;) {
		long long N;
		cin >> N;
		
		if (N <= 5)
			cout << V[5 - N] << "\n";
		else {
			long long** R = pow(M, N - 5);
			long long sum = 0;
			for (int j = 0;j < 5;j++)
				sum += R[0][j] * V[j];
			cout << sum % mod << "\n";
		}
	}
}