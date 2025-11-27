#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> L(N + 1);
	for (int i = 0;i < M;i++) {
		int A, B, C;
		cin >> A >> B >> C;
		L[A].push_back(make_pair(C, B));
	}
	int start, end;
	cin >> start >> end;

	priority_queue<pair<int, int>> Q;
	vector<int> dist;
	dist.resize(N + 1, 99999999);

	Q.push(make_pair(0, start));
	dist[start] = 0;

	for (;!Q.empty();) {
		int cost = -Q.top().first;
		int node = Q.top().second;
		Q.pop();

		if (node == end)
			break;
		if (cost > dist[node])
			continue;

		for (const auto& p : L[node]) {
			int new_cost = cost + p.first;
			int to = p.second;

			if (new_cost < dist[to]) {
				dist[to] = new_cost;
				Q.push(make_pair(-new_cost, to));
			}
		}
	}
	cout << dist[end];
}