#include <iostream>
using namespace std;

int A[502];
int dp[502][502];

int cost(int i,int j) {
	if (dp[i][j] != 0)
		return dp[i][j];
	if (j - i <= 1)
		return 0;

	int minimum = (1 << 30);
	for (int k = i + 1;k < j;k++)
		minimum = min(minimum, cost(i, k) + cost(k, j) + A[i] * A[k] * A[j]);

	dp[i][j] = minimum;
	return minimum;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
		cin >> A[i] >> A[i + 1];
	
	cout << cost(0, N);
}