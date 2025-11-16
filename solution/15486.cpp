#include <iostream>
using namespace std;

long long dp[1500001]{};
int T[1500001];
long long P[1500001];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1;i <= N;i++)
		cin >> T[i] >> P[i];

	long long maximum = 0;
	for (int i = 1;i <= N;i++) {
		maximum = max(maximum, dp[i - 1]);

		if (i + T[i] - 1 <= N)
			dp[i + T[i] - 1] = max(dp[i + T[i] - 1], maximum + P[i]);
	}
	maximum = max(maximum, dp[N]);
	cout << maximum;
}