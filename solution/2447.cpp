#include <iostream>
using namespace std;

bool A[7000][7000]{};

void f(int i, int j, int N, bool empty) {
	if (empty) {
		for (int x = 0;x < N;x++) {
			for (int y = 0;y < N;y++) {
				A[i + x][j + y] = true;
			}
		}
		return;
	}
	if (N <= 1)
		return;

	int n = N / 3;
	
	f(i + n, j + n, n, true);

	f(i, j, n, false);
	f(i + n, j, n, false);
	f(i + n + n, j, n, false);
	f(i + n + n, j + n, n, false);
	f(i + n + n, j + n + n, n, false);
	f(i + n, j + n + n, n, false);
	f(i, j + n + n, n, false);
	f(i, j + n, n, false);
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	f(0, 0, N, false);
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << (A[i][j] ? ' ' : '*');
		}
		cout << "\n";
	}
}