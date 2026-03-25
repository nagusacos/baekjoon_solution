#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;

void get_prime(int maximum) {
	prime.push_back(2);
	for (int n = 3;n <= maximum;n += 2) {
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	get_prime(M);
	for (const int& p : prime)
		if (p >= N)
			cout << p << "\n";
}