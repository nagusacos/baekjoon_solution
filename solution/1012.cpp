#include <iostream>
using namespace std;

int N, M, K;

int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

bool out_of_bound(int x,int y) {
	return x < 0 || N <= x || y < 0 || M <= y;
}

void fill(int A[51][51], int i, int j, int color) {
	for (int g = 0;g < 4;g++) {
		int x = i + di[g];
		int y = j + dj[g];
		if (out_of_bound(x, y) ? false : A[x][y] < 0) {
			A[x][y] = color;
			fill(A, x, y, color);
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (;T-- > 0;) {
		cin >> N >> M >> K;
		int A[51][51]{ 0, };
		int X, Y;
		for (int i = 0;i < K;i++) {
			cin >> X >> Y;
			A[X][Y] = -1;
		}
		int color = 1;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (A[i][j] < 0) {
					A[i][j] = color;
					fill(A, i, j, color++);
				}
			}
		}
		cout << color - 1 << "\n";
	}
}