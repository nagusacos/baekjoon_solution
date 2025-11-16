#include <iostream>
using namespace std;

int dp[1001][3]{};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int RGB[1001][3];
	for (int i = 1;i <= N;i++)
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];

	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;

	for (int i = 1;i <= N;i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + RGB[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + RGB[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + RGB[i][2];
	}
	cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);
}