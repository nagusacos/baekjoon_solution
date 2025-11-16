#include <iostream>
using namespace std;

int dp[301]{};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int A[301]{};
	for (int i = 1;i <= N;i++)
		cin >> A[i];
	dp[0] = 0;
	dp[1] = A[1];
	if (N > 1) {
		dp[2] = max(A[1] + A[2], A[2]);
		for (int i = 3;i <= N;i++)
			dp[i] = max(dp[i - 3] + A[i - 1], dp[i - 2]) + A[i];
	}
	
	cout << dp[N];
}