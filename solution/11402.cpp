#include <iostream>
using namespace std;

int C(int N,int K,int M) {
	if (N < K)
		return 0;
	K = min(K, N - K);
	int A = 1;
	for (int i = N - K + 1;i <= N;i++) A = (A * i) % M;
	int B = 1;
	for (int i = 1;i <= K;i++) B = (B * i) % M;
	int C = 1;
	for (int i = 0;i < 12;i++) {//2^12 > 2000
		if ((M - 2) & (1 << i))
			C = (C * B) % M;
		B = (B * B) % M;
	}
	return (A * C) % M;
}
int combination(long long N,long long K,long long M) {//by Lucas's theorem
	K = min(K, N - K);
	int S = 1;
	for (;N > 0;) {
		//cout << "C(" << N % M << ", " << K % M << ") = " << C(N % M, K % M, M) << "\n";
		S = (S * C(N % M, K % M, M)) % M;
		N /= M;
		K /= M;
	}
	return S;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	long long N, K, M;
	cin >> N >> K >> M;
	cout << combination(N, K, M);
}