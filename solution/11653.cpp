#include <iostream>
using namespace std;

void factorization(int n) {

	for (;n > 1;) {
		if (n % 2 == 0) {
			cout << 2 << "\n";
			n /= 2;
			continue;
		}

		bool prime = true;
		for (int i = 3;i * i <= n;i += 2) {
			if (n % i == 0) {
				cout << i << "\n";
				n /= i;
				prime = false;
				break;
			}
		}
		if (prime) {
			cout << n << "\n";
			break;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int N;
	cin>>N;
	factorization(N);
}