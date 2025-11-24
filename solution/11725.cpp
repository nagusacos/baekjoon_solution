#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<vector<int>> adj(N + 1);
	for (int i = 1;i <= N - 1;i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	int order[100001]{};
	order[1] = 1;
	int Q[100001];
	int q = 0;
	Q[q++] = 1;
	for (int n = 0;n < q;n++) {
		int cur = Q[n];
		for (const int& i : adj[cur]) {
			if (order[i]==0) {
				order[i] = cur;
				Q[q++] = i;
			}
		}
	}
	for (int i = 2;i <= N;i++)
		cout << order[i] << "\n";
}