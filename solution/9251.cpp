#include <iostream>
using namespace std;

char A[1001];
char B[1001];
int dp[1001][1001];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	for (int i = 0;i < 1001;i++) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}

	cin >> A >> B;

	int j, i;
	for (j = 0;B[j] != '\0';j++) {
		for (i = 0;A[i] != '\0';i++) {
			dp[i + 1][j + 1] = (A[i] == B[j] ? dp[i][j] + 1 : dp[i][j + 1] > dp[i + 1][j] ? dp[i][j + 1] : dp[i + 1][j]);
		}
	}
	cout << dp[i][j];
}