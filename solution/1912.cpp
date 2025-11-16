#include <iostream>
using namespace std;

int dp[100001]{};
int A[100001];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	dp[0] = 0;

	for (int i = 1;i <= N;i++) {
		cin >> A[i];
		dp[i] = max(dp[i - 1],0) + A[i];//continuous partial sum containing A[i]
	}

	int max = dp[1];
	for (int i = 2;i <= N;i++)
		if (dp[i] > max)
			max = dp[i];
	cout << max;
}