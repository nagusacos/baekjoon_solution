#include <iostream>
#include <vector>
using namespace std;

#define sq_bound 32000
vector<int> prime;

void init_prime(int N = sq_bound) {
	bool arr[sq_bound]{};
	for (int n = 2;n < sq_bound;n++) {
		if (!arr[n]) {
			prime.push_back(n);
			for (int i = n;i < sq_bound;i += n)
				arr[i]=true;
		}
	}
}
long long phi(int N) {
	vector<int> factor;

	int num = N;
	for (const int& p : prime) {
		bool is_factor = false;
		for (;num % p == 0;num /= p) is_factor = true;
		if (is_factor)
			factor.push_back(p);
	}
	if (num != 1)
		factor.push_back(num);

	for (const int& f : factor) {
		N /= f;
		N *= (f - 1);
	}

	return N;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	init_prime();

	int T;
	cin >> T;
	for (int i = 1;i <= T;i++) {
		int N;
		cin >> N;
		cout << phi(N + 1) << "\n";
	}
}