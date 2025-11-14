#include <iostream>
using namespace std;

int dp[42];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2;i <= 40;i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int T;
	cin >> T;
	for (;T-- > 0;) {
		int N;
		cin >> N;
		cout << (N - 1 < 0 ? 1 : dp[N - 1]) << " " << dp[N] << "\n";
	}
}