#include <iostream>
using namespace std;

#define MOD 1000000007
#define N 8

long long M[8][8] = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 1, 0},
	{0, 0, 0, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 1, 1, 0},
};

long long U[8][8] = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 1, 0},
	{0, 0, 0, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 1, 1, 0},
};

void matrix_mult(long long A[N][N], long long B[N][N]) {
	long long temp[N][N];
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			temp[i][j] = 0;
			for (int k = 0;k < N;k++)
				temp[i][j] += (A[i][k] * B[k][j]) % MOD;
		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			A[i][j] = temp[i][j] % MOD;
		}
	}
}
void matrix_pow(long long A[N][N], int n) {
	if (n <= 1)
		return;
	matrix_pow(A, n >> 1);
	matrix_mult(A, A);
	if (n & 1)
		matrix_mult(A, U);
	return;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int D;
	cin >> D;
	matrix_pow(M, D);
	cout << M[0][0];
}
