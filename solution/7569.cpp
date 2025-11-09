#include <iostream>
#include <queue>
using namespace std;

int A[101][101][101];
int di[6]{ 1,-1,0,0,0,0 };
int dj[6]{ 0,0,1,-1,0,0 };
int dk[6]{ 0,0,0,0,1,-1 };

int M, N, H;

queue<int*> Q;

bool out_of_bound(int i, int j,int k) {
	return i < 0 || N <= i || j < 0 || M <= j || k < 0 || H <= k;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> M >> N >> H;
	int* temp;
	for (int k = 0;k < H; k++) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				cin >> A[i][j][k];
				if (A[i][j][k] >= 1) {
					temp = new int[3] {i, j, k};
					Q.push(temp);
				}
			}
		}
	}
	

	int* current;
	for (;!Q.empty();) {
		current = Q.front();
		Q.pop();
		int x = current[0];
		int y = current[1];
		int z = current[2];
		for (int g = 0;g < 6;g++) {
			int i = x + di[g];
			int j = y + dj[g];
			int k = z + dk[g];
			if (out_of_bound(i, j, k) ? false : A[i][j][k] == 0) {
				A[i][j][k] = A[x][y][z] + 1;
				temp = new int[3] {i, j, k};
				Q.push(temp);
			}
		}
		delete[] current;
	}

	int max = 0;
	for (int k = 0;k < H; k++) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (A[i][j][k] > -1) {
					if (A[i][j][k] <= 0) {
						cout << "-1\n";
						return 0;
					}
					if (A[i][j][k] > max)
						max = A[i][j][k];
				}
			}
		}
	}
	cout << max - 1;
}

//general solution of tomato