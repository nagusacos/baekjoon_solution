#include <iostream>
using namespace std;

int dp[1000002];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4;i <= N;i++) {
		dp[i] = dp[i - 1];
		if (i % 2 == 0 && dp[i / 2] < dp[i])
			dp[i] = dp[i / 2];
		if (i % 3 == 0 && dp[i / 3] < dp[i])
			dp[i] = dp[i / 3];
		dp[i]++;
	}
	cout << dp[N];
}