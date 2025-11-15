#include <iostream>
using namespace std;

int W[101]{};
int V[101]{};
int dp[100001][101]{};


int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	for (int i = 1;i <= N;i++)
		cin >> W[i] >> V[i];

	for (int i = 1;i <= N;i++) {
		for (int k = 0;k < W[i];k++) {
			dp[k][i] = dp[k][i - 1];
		}
		for (int k = W[i];k <= K;k++) {
			dp[k][i] = max(dp[k - W[i]][i - 1] + V[i], dp[k][i - 1]);
		}
	}
	cout << dp[K][N];
}