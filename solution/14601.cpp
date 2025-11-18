#include <iostream>
using namespace std;

int A[200][200];
int order = 1;

int dir[4][2] = { {0,0},{0,1},{1,0},{1,1} };

void f(int i, int j,int N, int empty_i, int empty_j) {
	int n = N >> 1;
	int mark = 2 * (i + n <= empty_i) + (j + n <= empty_j);
	//01
	//23

	if (N <= 2) {
		for (int d = 0;d < 4;d++) {
			int x = i + dir[d][0];
			int y = j + dir[d][1];
			if (mark != d)
				A[x][y] = order;
		}
		order++;
		return;
	}

	//===
	
	for (int d = 0;d < 4;d++) {
		int x = i + n * dir[d][0];
		int y = j + n * dir[d][1];
		int empty_x = i + n - 1 + dir[d][0];
		int empty_y = j + n - 1 + dir[d][1];
		if (mark == d)
			f(x, y, n, empty_i, empty_j);
		else
			f(x, y, n, empty_x, empty_y);
	}
	f(i + n - 1, j + n - 1, 2, i + n - 1 + dir[mark][0], j + n - 1 + dir[mark][1]);
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, X, Y;
	cin >> N >> X >> Y;
	N = 1 << N;
	X--;
	Y--;
	f(0, 0, N, Y, X);
	A[Y][X] = -1;

	for (int i = N - 1;i >= 0;i--) {
		cout << A[i][0];
		for (int j = 1;j < N;j++)
			cout << " " << A[i][j];
		cout << "\n";
	}
}