#include <iostream>
using namespace std;

int gcd(int a,int b) {
	if (a <= 0)
		return b;
	if (b <= 0)
		return a;
	if (a < b)
		return gcd(a, b % a);
	return gcd(a % b, b);
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A, B;
	cin >> A >> B;
	int C = gcd(A, B);
	cout << C << "\n" << (A * B) / C;
}
