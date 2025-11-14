#include <iostream>
#include <queue>
using namespace std;

int N, M, V;

bool adj[1001][1001]{ 0, };
bool visit_BFS[1001]{ 0, };
bool visit_DFS[1001]{ 0, };

void BFS(int i) {
	queue<int> Q;
	visit_BFS[i] = true;
	Q.push(i);
	cout << i;//

	for (;!Q.empty();) {
		int j = Q.front();
		Q.pop();
		for (int k = 1;k <= N;k++) {
			if (adj[j][k] && !visit_BFS[k]) {
				visit_BFS[k] = true;
				Q.push(k);
				cout << " " << k;//
			}
		}
	}
}
void DFS(int i) {
	for (int j = 1;j <= N;j++) {
		if (adj[i][j] && !visit_DFS[j]) {
			visit_DFS[j] = true;
			cout << " " << j;//
			DFS(j);
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> V;
	int A, B;
	for (int i = 0;i < M;i++) {
		cin >> A >> B;
		adj[A][B] = true;
		adj[B][A] = true;
	}
	
	visit_DFS[V] = true;
	cout << V;
	DFS(V);
	cout << "\n";
	BFS(V);
}