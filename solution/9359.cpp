#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;

void get_prime(int N = 32000) {
	prime.push_back(2);
	for (int n = 3;n <= N;n += 2) {
		bool is_prime = true;
		for (const int& p : prime) {
			if (p * p > n)
				break;
			if (n % p == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime)
			prime.push_back(n);
	}
}

long long psi(int N, long long A) {
	if (N == 1 || A <= 1)
		return A;

	long long sum = A;

	vector<int> factor;
	for (const int& p : prime) {
		if (p * p > N)
			break;
		bool is_factor = false;
		for (;N % p == 0;N /= p) is_factor = true;
		if (is_factor)
			factor.push_back(p);
	}
	if (N != 1)
		factor.push_back(N);

	unsigned int cases = 1 << factor.size();
	for (unsigned int bit = 1;bit < cases;bit++) {
		int z = 1;
		bool even = true;
		for (int i = 0;i < factor.size();i++) {
			if (bit & (1 << i)) {
				z *= factor[i];
				even = !even;
			}
		}
		if (even) sum += A / z;
		else sum -= A / z;
	}
	factor.clear();

	return sum;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	get_prime();

	int T;
	cin >> T;
	for (int i = 1;i <= T;i++) {
		long long A, B, N;
		cin >> A >> B >> N;
		cout << "Case #" << i << ": " << psi(N, B) - psi(N, A - 1) << "\n";
	}
}
