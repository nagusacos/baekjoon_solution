#include <iostream>
#include <queue>
using namespace std;

int N;
int A[101][101];
int B[101][101];

int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };

bool out_of_bound(int i,int j) {
	return i < 0 || N <= i || j < 0 || N <= j;
}

void fill(int G[101][101], int si, int sj, int num) {
	queue<pair<int, int>> Q;
	Q.push(make_pair(si, sj));
	int color = G[si][sj];

	pair<int, int> current;
	for (;!Q.empty();) {
		current = Q.front();
		Q.pop();
		int x = current.first;
		int y = current.second;
		for (int dir = 0;dir < 4;dir++) {
			int i = x + dx[dir];
			int j = y + dy[dir];
			if (out_of_bound(i, j) ? false : G[i][j] == color) {
				G[i][j] = num;
				Q.push(make_pair(i, j));
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	
	cin >> N;
	char temp;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> temp;
			A[i][j] = (temp == 'B' ? -1 : temp == 'G' ? -2 : -3);
			B[i][j] = (temp == 'B' ? -1 : -2);
		}
	}
	int A_count = 0, B_count = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (A[i][j] < 0)
				fill(A, i, j, A_count++);
			if (B[i][j] < 0)
				fill(B, i, j, B_count++);
		}
	}
	cout << A_count << " " << B_count;
}
