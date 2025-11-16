#include <iostream>
using namespace std;

#define mod 1000000000

long long dp[101][10];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	dp[1][0] = 0;
	for (int k = 1;k <= 9;k++)
		dp[1][k] = 1;

	for (int i = 2;i <= N;i++) {
		dp[i][0] = dp[i - 1][1];
		for (int k = 1;k <= 8;k++)
			dp[i][k] = (dp[i - 1][k - 1] + dp[i - 1][k + 1]) % mod;
		dp[i][9] = dp[i - 1][8];
	}

	long long sum = 0;
	for (int k = 0;k <= 9;k++)
		sum += dp[N][k];

	cout << sum % mod;
}