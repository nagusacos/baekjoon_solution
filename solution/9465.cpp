#include <iostream>
using namespace std;

int A[100002][2];
int dp[100002][2];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (;T-- > 0;) {
		int N;
		cin >> N;
		for (int i = 1;i <= N;i++)
			cin >> A[i][0];
		for (int i = 1;i <= N;i++)
			cin >> A[i][1];

		int pre_max = 0;
		dp[1][0] = A[1][0];
		dp[1][1] = A[1][1];
		for (int i = 2;i <= N;i++) {
			pre_max = max(pre_max, max(dp[i - 2][0], dp[i - 2][1]));
			dp[i][0] = A[i][0] + max(pre_max, dp[i - 1][1]);
			dp[i][1] = A[i][1] + max(pre_max, dp[i - 1][0]);
		}
		int a = max(dp[N][0], dp[N][1]);
		int b = max(dp[N - 1][0], dp[N - 1][1]);
		cout << max(max(a, b), pre_max) << "\n";
	}
}