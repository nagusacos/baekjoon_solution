#include <iostream>
#include <queue>
using namespace std;

#define MAX 10000001

int A[1003][1003];
int D[1003][1003];

queue<pair<int, pair<int, int>>> Q;

void f(int depth, int i, int j) {
	bool up = (A[i + 1][j] >= 0 && D[i + 1][j] >= MAX);
	bool down = (A[i - 1][j] >= 0 && D[i - 1][j] >= MAX);
	bool right = (A[i][j + 1] >= 0 && D[i][j + 1] >= MAX);
	bool left = (A[i][j - 1] >= 0 && D[i][j - 1] >= MAX);

	if (!up && !down && !right && !left)
		return;

	if (up) {
		D[i + 1][j] = depth + 1;
		Q.push(make_pair(depth + 1, make_pair(i + 1, j)));
	}
	if (down) {
		D[i - 1][j] = depth + 1;
		Q.push(make_pair(depth + 1, make_pair(i - 1, j)));
	}
	if (right) {
		D[i][j + 1] = depth + 1;
		Q.push(make_pair(depth + 1, make_pair(i, j + 1)));
	}
	if (left){
		D[i][j - 1] = depth + 1;
		Q.push(make_pair(depth + 1, make_pair(i, j - 1)));
	}
}

void search() {
	int depth, i, j;
	for (;!Q.empty();) {
		depth = Q.front().first;
		i = Q.front().second.first;
		j = Q.front().second.second;
		f(depth, i, j);
		Q.pop();
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int M, N;
	cin >> M >> N;

	//bound
	for (int i = 0;i <= N + 1;i++) {
		A[i][0] = -1;
		A[i][M + 1] = -1;
		D[i][0] = MAX;
		D[i][M + 1] = MAX;
	}
	for (int j = 0;j <= M + 1;j++) {
		A[0][j] = -1;
		A[N + 1][j] = -1;
		D[0][j] = MAX;
		D[N + 1][j] = MAX;
	}

	//field
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> A[i][j];
			D[i][j] = MAX;
			if (A[i][j] >= 1) {
				Q.push(make_pair(0, make_pair(i, j)));
				D[i][j] = 0;
			}
		}
	}

	search();

	//check
	int max = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (A[i][j] != -1) {
				if (D[i][j] >= MAX) {
					cout << "-1";
					return 0;
				}
				if (D[i][j] > max)
					max = D[i][j];
			}
		}
	}
	cout << max;
}