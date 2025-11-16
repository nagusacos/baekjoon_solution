#include <iostream>
using namespace std;

long long dp[91];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2;i <= N;i++)
		dp[i] = dp[i - 2] + dp[i - 1];
	cout << dp[N];
}