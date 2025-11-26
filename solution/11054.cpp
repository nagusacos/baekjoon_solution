#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int A[1001];
	for (int i = 1;i <= N;i++)
		cin >> A[i];
		
	int dp[1002]{};
	int reverse_dp[1002]{};

	for (int i = 1;i <= N;i++) {
		int idx = N + 1 - i;

		int m = 0;
		int reverse_m = 0;
		for (int k = 1;k < i;k++) {
			if (A[i - k] < A[i])
				m = max(m, dp[i - k]);

			if (A[idx + k] < A[idx])
				reverse_m = max(reverse_m, reverse_dp[idx + k]);
		}
		dp[i] = m + 1;
		reverse_dp[idx] = reverse_m + 1;
	}
	int m = 0;
	for (int i = 1;i <= N;i++)
		m = max(m, dp[i] + reverse_dp[i] - 1);
	cout << m;
}