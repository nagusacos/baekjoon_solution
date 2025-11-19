#include <iostream>
using namespace std;

#define mod 1000;

long long N, K;

long long** M;

void mult(long long** C , long long** A, long long** B ){
	long long temp[5][5];
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			long long sum = 0;
			for (int k = 0;k < N;k++)
				sum += A[i][k] * B[k][j];
			temp[i][j] = sum;
		}
	}
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			C[i][j] = temp[i][j] % mod;
}
long long** pow(long long** A,long long num){
	if (num <= 1)
		return A;

	long long n = num >> 1;
	long long** F = pow(A, n);
	long long** Z = new long long* [N];
	for (int i = 0;i < N;i++)
		Z[i] = new long long[N];

	mult(Z, F, F);

	if (num % 2 != 0)
		mult(Z, M, Z);

	return Z;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	M = new long long* [N];
	for (int i = 0;i < N;i++) {
		M[i] = new long long[N];
		for (int j = 0;j < N;j++)
			cin >> M[i][j];
	}
	
	long long** R = pow(M, K);

	for (int i = 0;i < N;i++) {
		cout << R[i][0] % mod;
		for (int j = 1;j < N;j++)
			cout << " " << R[i][j] % mod;
		cout << "\n";
	}
}