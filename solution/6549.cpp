#include <iostream>
using namespace std;

long long A[100001];

long long f(int i, int j) {
	if (i == j)
		return A[i];
	int m = (i + j) / 2;

	long long L = f(i, m);
	long long R = f(m + 1, j);

	long long h = min(A[m], A[m + 1]);
	long long S = h * 2;

	int a = m - 1, b = m + 2;
	for (;i <= a && b <= j;) {
		if (A[a] < A[b]) {
			h = min(h, A[b]);
			b++;
		}
		else {
			h = min(h, A[a]);
			a--;
		}
		S = max(S, h * (b - a - 1));
	}
	for (;i <= a;) {
		h = min(h, A[a]);
		a--;
		S = max(S, h * (b - a - 1));
	}
	for (;b <= j;) {
		h = min(h, A[b]);
		b++;
		S = max(S, h * (b - a - 1));
	}
	return max(S, max(L, R));
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	for (;;) {
		int N;
		cin >> N;
		if (N <= 0)
			break;
		for (int i = 0;i < N;i++)
			cin >> A[i];

		cout << f(0, N - 1) << "\n";
	}
}