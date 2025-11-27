#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int A[21][21];
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> A[i][j];
		}
	}
	unsigned int U = (~0 + (1 << N));
	int value = 999999999;
	for (unsigned int subset = U;subset >= (1 << N - 1);subset = (subset + ~0) & U) {
		unsigned int complement = (~subset + (1 << N));
		if ((subset & (subset + ~0)) == 0 || (complement & (complement + ~0)) == 0)
			continue;
		int l = 0;
		int r = 0;
		for (int i = 0;i < N - 1;i++) {
			for (int j = i + 1;j < N;j++) {
				if ((subset & (1 << i)) && (subset & (1 << j))) {
					l += A[i][j] + A[j][i];
				}
				else if ((complement & (1 << i)) && (complement & (1 << j))) {
					r += A[i][j] + A[j][i];
				}
			}
		}
		value = min(value, abs(l - r));
	}
	cout << value;
}