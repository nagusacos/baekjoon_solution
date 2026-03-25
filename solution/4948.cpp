#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;

void get_prime(int maximum) {
	if (maximum <= 1)
		return;
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
int sup(int val) {
	int a = 0, b = prime.size() - 1;
	for (;a < b;) {
		int m = (a + b) >> 1;
		if (val <= prime[m])
			b = m;
		else
			a = m + 1;
	}
	return a;
}
int inf(int val) {
	int a = 0, b = prime.size() - 1;
	for (;a < b;) {
		int m = (a + b) >> 1;
		if (prime[m + 1] <= val)
			a = m + 1;
		else
			b = m;
	}
	return a;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	get_prime(250000);

	for (;;) {
		int N;
		cin >> N;
		if (N == 0)
			break;

		int i = sup(N + 1);
		int j = inf(N + N);
		cout << j - i + 1 << "\n";
	}
}
