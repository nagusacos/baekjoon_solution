#include <iostream>
using namespace std;

long long mult(const long long a, const long long b) {
	return (a * b) % 1000000007;
}

int N, M, K;
long long A[4000001];
long long seg[4000001];
long long (*f)(const long long, const long long) = mult;

void init(int i = 0, int j = N - 1, int n = 1) {
	if (i >= j) {
		seg[n] = A[i];
		return;
	}
	int m = (i + j) / 2;
	int l = 2 * n, r = 2 * n + 1;
	init(i, m, l);
	init(m + 1, j, r);
	seg[n] = f(seg[l], seg[r]);
}

void update(int idx, long long k, int i = 0, int j = N - 1, int n = 1) {
	if (i >= j) {
		seg[n] = k;
		return;
	}
	int m = (i + j) / 2;
	int l = 2 * n, r = 2 * n + 1;
	if (idx <= m)
		update(idx, k, i, m, l);
	else
		update(idx, k, m + 1, j, r);
	seg[n] = f(seg[l], seg[r]);
}

long long interval(int a, int b, long long ground = 1, int i = 0, int j = N - 1, int n = 1) {
	if (j < a || b < i)
		return ground;
	else if (a <= i && j <= b)
		return seg[n];
	int m = (i + j) / 2;
	int l = 2 * n, r = 2 * n + 1;
	return f(interval(a, b, ground, i, m, l), interval(a, b, ground, m + 1, j, r));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> K;
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	init();

	for (int i = 0;i < M + K;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a <= 1) {
			b--;
			update(b, c);
		}
		else {
			b--;
			c--;
			cout << interval(b, c) << "\n";
		}
	}
}