#include <iostream>
#include <vector>
using namespace std;

#define bound 10001
int mpf[bound]{};
long long seq[bound]{};

void init_mpf(int N = bound) {
	for (int n = 2;n <= N;n++) {
		if (!mpf[n]) {
			for (int i = n;i <= N;i += n) {
				if (!mpf[i]) {
					mpf[i] = n;
				}
			}
		}
	}
}
long long phi(int N) {
	vector<int> factor;

	int pre = 0;
	int n = N;
	for (;n != mpf[n];n /= mpf[n]) {
		if (pre != mpf[n]) {
			pre = mpf[n];
			factor.push_back(mpf[n]);
		}
	}
	if (pre != n)
		factor.push_back(n);

	for (const int& p : factor) {
		N /= p;
		N *= (p - 1);
	}

	return N;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	init_mpf();

	seq[1] = 2;
	for (int i = 2;i < bound;i++) {
		seq[i] = seq[i - 1] + phi(i);
	}

	int T;
	cin >> T;
	for (int i = 1;i <= T;i++) {
		int idx, N;
		cin >> idx >> N;
		cout << idx << " " << seq[N] << "\n";
	}
}