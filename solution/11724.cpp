#include <iostream>
using namespace std;

bool adj[1001][1001]{};

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

	int order[1001]{};
	int Q[1001]{};
	int q = 0;

	int n = 0;
	int component = 0;

	for (int k = 1;k <= N;k++) {
		if (order[k] <= 0) {
			order[k] = 1;
			Q[q++] = k;

			for (;n < q;n++) {
				int i = Q[n];
				for (int j = 1;j <= N;j++) {
					if (adj[i][j]) {
						if (order[j] <= 0) {
							order[j] = order[i] + 1;
							Q[q++] = j;
						}
					}
				}
			}
			component++;
		}
	}
	cout << component;
}