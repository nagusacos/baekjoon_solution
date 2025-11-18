#include <iostream>
using namespace std;

int A[1000001];

int dp[1000001]{ 0, };
int bound[1000001]{ -1000000001, };//watch out "bound range"
int len = 1;

int seq[1000001];
int s = 0;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1;i <= N;i++)
		cin >> A[i];

	for (int i = 1;i <= N;i++) {
		int l = 0;
		int r = len - 1;
		for (;l < r;) {
			int m = (l + r) / 2;
			if (bound[m] < A[i])//find inf
				l = m + 1;
			else
				r = m;
		}

		if (r >= len - 1 && bound[r] < A[i]) {
			len++;
			r++;
			bound[r] = A[i];
		}

		dp[i] = r;

		if (A[i] < bound[r])
			bound[r] = A[i];
	}

	cout << len - 1 << "\n";

	int order = len - 1;
	for (int i = N;i > 0 && order > 0;i--) {
		if (dp[i] == order) {
			seq[s++] = A[i];
			order--;
		}
	}

	s--;
	cout << seq[s--];
	for (;s>=0;)
		cout << " " << seq[s--];
}