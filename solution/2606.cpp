#include <iostream>
using namespace std;

bool adj[101][101]{};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	
	for (int i = 0;i < M;i++) {
		int A, B;
		cin >> A >> B;
		adj[A][B] = true;
		adj[B][A] = true;
	}
	
	int order[102]{ 0, };
	int Q[102];
	int q = 0;
	Q[q++] = 1;

	int count = 1;
	order[1] = count++;
	for (int n = 0;n < q;n++) {
		int i = Q[n];
		for (int j = 1;j <= N;j++) {
			if (adj[i][j] && order[j] <= 0) {
				order[j] = count++;
				Q[q++] = j;
			}
		}
	}
	cout << count - 2;
}