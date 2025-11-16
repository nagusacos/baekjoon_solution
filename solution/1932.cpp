#include <iostream>
using namespace std;

int dp[502][502]{};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int A[501][501];
	for (int i = 1;i <= N;i++)
		for (int j = 1;j <= i;j++)
			cin >> A[i][j];

	for (int i = 1;i <= N;i++)
		for (int j = 1;j <= i;j++)
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + A[i][j];

	int max = 0;
	for (int j = 1;j <= N;j++)
		if (dp[N][j] > max)
			max = dp[N][j];

	cout << max;
}