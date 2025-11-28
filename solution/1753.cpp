#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX (1 << 30)

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	priority_queue<pair<int, int>> Q;
	int N, M, start;
	cin >> N >> M >> start;
	vector<pair<int, int>> adj[20001];
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
	}

	vector<int> dist;
	dist.resize(20001, MAX);

	Q.push(make_pair(0, start));
	dist[start] = 0;

	for (;!Q.empty();) {
		int cur_cost = -Q.top().first;
		int cur_num = Q.top().second;
		Q.pop();

		for (const auto& to : adj[cur_num]) {
			int cost = cur_cost + to.first;
			int num = to.second;
			if (dist[num] > cost) {
				dist[num] = cost;
				Q.push(make_pair(-cost, num));
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dist[i] != MAX)
			cout << dist[i] << '\n';
		else
			cout << "INF\n";
	}
}