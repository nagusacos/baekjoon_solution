#include <iostream>
using namespace std;

int dp[102]{};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int T[101];
	int P[101];
	for (int i = 1;i <= N;i++)
		cin >> T[i] >> P[i];

	int maximum = 0;
	for (int i = 1;i <= N;i++) {
		maximum = max(maximum, dp[i - 1]);

		if (i + T[i] - 1 <= N)
			dp[i + T[i] - 1] = max(dp[i + T[i] - 1], maximum + P[i]);
	}
	maximum = max(maximum, dp[N]);
	cout << maximum;
}