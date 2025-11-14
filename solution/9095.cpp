#include <iostream>
using namespace std;

int dp[12];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	dp[1] = 1;//1
	dp[2] = 2;//2 1+1
	dp[3] = 4;//3 1+2 2+1 1+1+1

	for (int i = 4;i <= 11;i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]; //I can't prove it. just intuitive
	}

	int T;
	cin >> T;
	for (;T-- > 0;) {
		int N;
		cin >> N;
		cout << dp[N] << "\n";
	}
}

//