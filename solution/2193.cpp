#include <iostream>
using namespace std;

long long dp[91]{};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	long long p_sum = 1;
	for (int i = 3;i <= N;i++) {
		dp[i] = p_sum + 1; //previous and 10000...0
		p_sum += dp[i - 1];
	}
	cout << dp[N];
}