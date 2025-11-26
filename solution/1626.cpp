#include <iostream>
using namespace std;

int mult(const long long &A, const long long& B, const long long& C) {
	if (B <= 1)
		return A % C;
	long long n = B / 2;
	long long F = mult(A, n, C);
	F = (F * F) % C;
	if (B & 1)
		F = (F * A) % C;
	return F;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	long long A, B, C;
	cin >> A >> B >> C;
	cout << mult(A, B, C);
}