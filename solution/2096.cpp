#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int A[3]{};
	int max_dp[3]{};
	int min_dp[3]{};

	for (int i = 0;i < N;i++) {
		cin >> A[0] >> A[1] >> A[2];

		max_dp[0] = max(max_dp[0], max_dp[1]);
		max_dp[2] = max(max_dp[1], max_dp[2]);
		max_dp[1] = max(max_dp[0], max_dp[2]);
		max_dp[0] += A[0];
		max_dp[1] += A[1];
		max_dp[2] += A[2];

		min_dp[0] = min(min_dp[0], min_dp[1]);
		min_dp[2] = min(min_dp[1], min_dp[2]);
		min_dp[1] = min(min_dp[0], min_dp[2]);
		min_dp[0] += A[0];
		min_dp[1] += A[1];
		min_dp[2] += A[2];
	}
	cout << max(max_dp[0], max(max_dp[1], max_dp[2])) << " " << min(min_dp[0], min(min_dp[1], min_dp[2]));
}