#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	cin.ignore();
	for (int i = 1;i <= T;i++) {
		int A, B;
		cin >> A >> B;
		cout << "Case #" << i << ": " << A << " + " << B << " = " << A + B << "\n";
	}
}
