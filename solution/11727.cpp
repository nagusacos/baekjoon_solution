#include <iostream>
using namespace std;

int dp[1001];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A;
	cin >> A;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3;i <= A;i++){
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 2];
		if (dp[i] >= 10007)
			dp[i] %= 10007;
	}
	cout << dp[A];
}