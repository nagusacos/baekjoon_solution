#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (;T-- > 0;) {
		int N;
		cin >> N;

		int A[102][2]{};
		for (int i = 0;i <= N + 1;i++)
			cin >> A[i][0] >> A[i][1];

		bool order[102]{};
		order[0] = true;

		int Q[102][2]{};
		int q = 0;
		Q[q][0] = A[0][0];
		Q[q][1] = A[0][1];
		q++;
		for (int n = 0;n < q;n++) {
			for (int k = 0;k <= N;k++) {
				if (abs(A[k][0] - Q[n][0]) + abs(A[k][1] - Q[n][1]) <= 1000) {//distance
					if (!order[k]) {
						order[k] = true;
						Q[q][0] = A[k][0];
						Q[q][1] = A[k][1];
						q++;
					}
				}
			}
			if (abs(A[N+1][0] - Q[n][0]) + abs(A[N+1][1] - Q[n][1]) <= 1000) {//distance
				order[N + 1] = true;
				break;
			}
		}
		cout << (order[N + 1] ? "happy\n" : "sad\n");
	}
}