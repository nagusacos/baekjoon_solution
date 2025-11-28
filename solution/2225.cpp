#include <iostream>
using namespace std;

long long dp[201][201]{};
bool check[201][201]{};

long long f(int N, int K) {
	if (check[N][K])
		return dp[N][K];
	if (K <= 1)
		return 1;

	long long sum = 0;
	for (int i = 0; i <= N; i++) {
		sum += f(i, K - 1);
		sum %= 1000000000;
	}
	dp[N][K] = sum;
	check[N][K] = true;
	return sum;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	cout << f(N, K);
}