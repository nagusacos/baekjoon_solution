#include <iostream>
using namespace std;

#define mod 1000000007

long long** A = new long long*[2];

void mult(long long** to, long long** G, long long** H) {
	long long a = (G[0][0] * H[0][0] + G[0][1] * H[1][0]) % mod;
	long long b = (G[1][0] * H[0][0] + G[1][1] * H[1][0]) % mod;
	long long  c = (G[0][0] * H[0][1] + G[0][1] * H[1][1]) % mod;
	long long  d = (G[1][0] * H[0][1] + G[1][1] * H[1][1]) % mod;
	to[0][0] = a;
	to[1][0] = b;
	to[0][1] = c;
	to[1][1] = d;
}

long long** f(long long  N){
	if (N <= 1)
		return A;

	long long  n = N / 2;
	long long** M = f(n);
	long long** F = new long long*[2];
	F[0] = new long long[2];
	F[1] = new long long[2];

	mult(F, M, M);
	if (N % 2 == 1)
		mult(F, F, A);
	return F;
}


int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	A[0] = new long long[2];
	A[1] = new long long[2];
	A[0][0] = 1;
	A[1][0] = 1;
	A[0][1] = 1;
	A[1][1] = 0;

	long long  N;
	cin >> N;
	long long** F = f(N);
	cout << F[0][1];
}