#include <iostream>
using namespace std;

long long dp[101]{};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	for (int i = 5;i <= 101;i++)
		dp[i] = dp[i - 1] + dp[i - 5];

	int T;
	cin >> T;
	for (;T-- > 0;) {
		int N;
		cin >> N;

		cout << dp[N] << "\n";
	}
}