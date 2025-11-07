#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string A;
	cin >> A;
	cout << fixed;
	cout.precision(1);
	if (A[0] == 'F')
		cout << 0.0f;
	else
		cout << (A[0] == 'A' ? 4 : A[0] == 'B' ? 3 : A[0] == 'C' ? 2 : 1) + (A[1] == '+' ? 0.3f : A[1] == '0' ? 0.0f : -0.3f);
}