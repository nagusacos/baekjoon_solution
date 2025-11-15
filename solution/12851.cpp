#include <iostream>
using namespace std;

int way[100002]{ 0, };
int order[100002]{ 0, };
int Q[100002];
int q = 0;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;


	way[N] = 1;
	order[N] = 1;
	Q[q++] = N;

	int n = 0;
	for (bool loop = true;loop && n < q;n++) {
		int i = Q[n];
		int dir[3] = { i * 2,i - 1,i + 1 };
		for (int k = 0;k < 3;k++) {
			if (dir[k] <= 100000 && dir[k] >= 0) {
				if(order[dir[k]] == order[i] + 1)
					way[dir[k]] += way[i];

				if (order[dir[k]] <= 0) {
					way[dir[k]] += way[i];

					order[dir[k]] = order[i] + 1;
					Q[q++] = dir[k];

					if (dir[k] == K) {
						loop = false;
						break;
					}
				}
			}
		}
	}
	for (;n < q;n++) {
		int i = Q[n];
		if (order[i] >= order[K])
			break;
		int dir[3] = { i * 2,i - 1,i + 1 };
		for (int k = 0;k < 3;k++) {
			if (dir[k] == K)
				way[K]++;
		}
	}

	cout << order[K] - 1 << "\n" << way[K];
}