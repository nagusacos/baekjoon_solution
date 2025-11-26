#include <iostream>
using namespace std;

int A[1025][1025]{};
int dp[1025][1025]{};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> A[i][j];
			dp[i][j] = A[i][j] + dp[i][j - 1];
		}
	}
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			dp[i][j] += dp[i - 1][j];
		}
	}
	for (int i = 0;i < M;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1] << "\n";
	}
}