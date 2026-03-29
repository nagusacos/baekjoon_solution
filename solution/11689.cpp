#include <iostream>
#include <vector>
using namespace std;

#define sq_bound 1000001

long long phi(long long N) {
	long long ph = N;
	vector<long long> factor;
	bool check[sq_bound]{};
	for (long long n = 2;n * n <= N;n++) {
		if (!check[n]) {
			bool is_factor = false;
			for (;N % n == 0;N /= n) is_factor = true;
			if (is_factor)
				factor.push_back(n);

			for (long long i = n * n;i < sq_bound;i += n) {
				check[i] = true;
			}
		}
	}
	if (N != 1)
		factor.push_back(N);

	for (const long long& f : factor) {
		ph /= f;
		ph *= (f - 1);
	}
	return ph;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	long long N;
	cin >> N;
	cout << phi(N);
}
