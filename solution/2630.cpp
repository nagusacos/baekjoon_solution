#include <iostream>
using namespace std;

bool A[128][128]{ 0, };

int color[2]{0, };

bool f(int i, int j, int N) {
	if (N <= 1)
		return true;

	int n = N >> 1;

	bool a = f(i, j, n);
	bool b = f(i + n, j, n);
	bool c = f(i, j + n, n);
	bool d = f(i + n, j + n, n);
	if (a && b && c && d && A[i][j] == A[i + n][j] && A[i + n][j] == A[i][j + n] && A[i][j + n] == A[i + n][j + n])
		return true;

	if (a)
		color[A[i][j]]++;
	if (b)
		color[A[i + n][j]]++;
	if (c)
		color[A[i][j + n]]++;
	if (d)
		color[A[i + n][j + n]]++;

	return false;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			cin >> A[i][j];

	bool a = f(0, 0, N);
	if (a)
		color[A[0][0]]++;
	cout << color[0] << "\n" << color[1];
}