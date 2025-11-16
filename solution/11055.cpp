#include <iostream>
using namespace std;

int A[1001]{};
int dp[1001]{};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int result = 0;
	for (int i = 1;i <= N;i++) {
		cin >> A[i];
		
		int maximum=0;
		for (int j = i - 1;j > 0;j--)
			if (A[j] < A[i])//strictly increasing sequence
				maximum = max(maximum, dp[j]);
		dp[i] += maximum + A[i];

		if (dp[i] > result)
			result = dp[i];
	}
	cout << result;
}