#include <iostream>
using namespace std;

int N, M;

int A[101][101];

bool out_of_bound(int i,int j) {
	return i < 0 || N <= i || j < 0 || M <= j;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			A[i][j] = (int)temp - 48;
		}
	}

	int Qx[10001];
	int Qy[10001];
	int q = 0;
	Qx[q] = 0;
	Qy[q] = 0;
	q++;

	A[0][0] = 2;

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	for (int n = 0; n < q; n++) {
		int x = Qx[n];
		int y = Qy[n];
		for (int d = 0; d < 4; d++) {
			int i = x + dx[d];
			int j = y + dy[d];
			if ((out_of_bound(i, j) ? false : (A[i][j] == 1))) {
				//cout << i << " " << j << "\n";
				Qx[q] = i;
				Qy[q] = j;
				q++;
				A[i][j] = A[x][y] + 1;
				if (i == N && j == M) {
					n = q;
					break;
				}
			}
		}
	}
	cout << A[N - 1][M - 1] - 1;

}