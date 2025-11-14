#include <iostream>
using namespace std;

char A[102];
char B[102];
char C[102];
int dp[102][102][102]{};

int main()
{
	cin >> (A + 1) >> (B + 1) >> (C + 1);

	int i = 1, j = 1, k = 1;
	for (i = 1; A[i] != '\0'; i++) {
		for (j = 1; B[j] != '\0';j++) {
			for (k = 1; C[k] != '\0'; k++) {
				if (A[i] == B[j] && B[j] == C[k])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
					dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
			}
		}
	}
	i--;
	j--;
	k--;
	cout << dp[i][j][k];
}
