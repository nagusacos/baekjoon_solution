#include <iostream>
#include <queue>
using namespace std;

int N,M;
int A[1001][1001];

int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };

bool out_of_bound(int i,int j) {
	return i < 0 || N <= i || j < 0 || M <= j;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	queue<pair<int, int>> Q;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> A[i][j];
			if (A[i][j] >= 2) {
				Q.push(make_pair(i, j));
			}
		}
	}

	pair<int, int> current;
	for (;!Q.empty();) {
		current = Q.front();
		Q.pop();
		int x = current.first;
		int y = current.second;
		for (int dir = 0;dir < 4;dir++) {
			int i = x + dx[dir];
			int j = y + dy[dir];
			if (out_of_bound(i, j) ? false : A[i][j] == 1) {
				A[i][j] = A[x][y] + 1;
				Q.push(make_pair(i, j));
			}
		}
	}
	for (int i = 0;i < N;i++) {
		if (A[i][0] > 0)
			cout << A[i][0] - 2;
		else
			cout << 0;
		for (int j = 1;j < M;j++) {
			if (A[i][j] > 0)
				cout << " " << A[i][j] - 2;
			else
				cout << " " << 0;
		}
		cout << "\n";
	}
}