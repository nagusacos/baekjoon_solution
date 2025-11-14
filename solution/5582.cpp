#include <iostream>
using namespace std;

char A[4002];
char B[4002];
int dp[4002][4002]{};

int main()
{
	cin >> (A + 1) >> (B + 1);

	int i = 1, j = 1;
	int max = 0;
	for (i = 1; A[i] != '\0'; i++) {
		for (j = 1; B[j] != '\0';j++) {
			if (A[i] == B[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			if (dp[i][j] > max)
				max = dp[i][j];
		}
	}
	cout << max;
}