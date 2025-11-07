#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A, B;
	for (;;) {
		cin >> A >> B;
		if (A == 0 && B == 0)
			break;
		cout << A + B << "\n";
	}
}