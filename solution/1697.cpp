#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	int order[100002]{ 0, };
	order[N] = 1;

	int Q[100002];
	int q = 0;
	Q[q++] = N;

	for (int n=0;n<q;n++) {
		int i = Q[n];
		int dir[3] = { i * 2,i - 1,i + 1 };
		for (int k = 0;k < 3;k++) {
			if (order[dir[k]] <= 0 && dir[k] <= 100000 && dir[k] >= 0) {
				order[dir[k]] = order[i] + 1;
				Q[q++] = dir[k];
				if (dir[k] == K) {
					n = q;
					break;
				}
			}
		}
	}
	cout << order[K] - 1;
}