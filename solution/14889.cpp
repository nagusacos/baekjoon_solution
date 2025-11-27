#include <iostream>
using namespace std;

int N;
int A[21][21];
int value = 999999999;

void eval(unsigned int take) {
	unsigned int complement = (~take + (1 << N));
	int l = 0;
	int r = 0;
	for (int i = 0;i < N - 1;i++) {
		for (int j = i + 1;j < N;j++) {
			if ((take & (1 << i)) && (take & (1 << j))) {
				l += A[i][j] + A[j][i];
			}
			else if ((complement & (1 << i)) && (complement & (1 << j))) {
				r += A[i][j] + A[j][i];
			}
		}
	}
	value = min(value, abs(l - r));
}

void f(unsigned int take,int n,int k) {
	if (k <= 0) {
		eval(take);
		return;
	}
	for (int i = n - 1;i >= 0;i--)
		f(take | (1 << i), i, k - 1);
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			cin >> A[i][j];

	f(0, N, N / 2);
	cout << value;
}