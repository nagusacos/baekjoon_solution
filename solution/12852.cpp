#include <iostream>
using namespace std;

int dp[1000001]{};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	dp[1] = 0;
	for (int i = 2;i <= N;i++) {
		dp[i] = dp[i - 1];
		if (i % 2 == 0)
			dp[i] = min(dp[i],dp[i / 2]);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3]);
		dp[i]++;
	}

	int* track = new int[dp[N] + 1];
	int len = 0;
	track[len++] = N;
	for (int pre = N;pre != 1;) {
		int reverse = pre - 1;
		if (pre % 2 == 0 && dp[pre / 2] < dp[pre])
			reverse = pre / 2;
		if (pre % 3 == 0 && dp[pre / 3] < dp[pre])
			reverse = pre / 3;
		pre = reverse;
		track[len++] = reverse;
	}

	cout << dp[N] << "\n" << track[0];
	for (int i = 1;i < len;i++)
		cout << " " << track[i];
}