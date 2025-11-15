#include <iostream>
using namespace std;

void f(int a, int b, int c, int n) {
	if (n <= 1) {
		cout << a << " " << c << "\n";
		return;
	}
		
	f(a, c, b, n - 1);
	cout << a << " " << c << "\n";
	f(b, a, c, n - 1);
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	cout << (1 << N) - 1 << "\n";
	f(1, 2, 3, N);
}