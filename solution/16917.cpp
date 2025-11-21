#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	cout << (X - min(X, Y)) * min(A, 2 * C) + (Y - min(X, Y)) * min(B, 2 * C) + min(X, Y) * min(A + B, 2 * C);
}