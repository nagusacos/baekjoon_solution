#include <iostream>
using namespace std;

long long A[1000001];
long long seg[4000004];
void init_seg(int i, int j, int n = 1) {
	if (i >= j) {
		seg[n] = A[i];
		return;
	}
	int m = (i + j) / 2;
	init_seg(i, m, n * 2);
	init_seg(m + 1, j, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}
void updata(int idx, long long k, int N) {
	long long delta = k - A[idx];
	int i = 0, j = N - 1, n = 1;
	seg[n] += delta;
	for (;i<j;) {
		int m = (i + j) / 2;
		if (m < idx) {
			n = n * 2 + 1;
			i = m + 1;
		}
		else {
			n = n * 2;
			j = m;
		}
		seg[n] += delta;
	}
	A[idx] = k;
}
long long p_sum(int i, int j, int a, int b, int n = 1) {
	if (a <= i && j <= b)
		return seg[n];
	else if (j < a || b < i)
		return 0;

	int m = (i + j) / 2;
	long long l = p_sum(i, m, a, b, n * 2);
	long long r = p_sum(m + 1, j, a, b, n * 2 + 1);
	return l + r;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	init_seg(0, N - 1);
	for (int i = 0;i < M + K;i++) {
		long long  a, b, c;
		cin >> a >> b >> c;
		if (a <= 1)
			updata(b - 1, c, N);
		else
			cout << p_sum(0, N - 1, b - 1, c - 1) << "\n";
	}
}