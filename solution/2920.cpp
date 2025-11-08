#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int A, result = 0;

	cin >> A;
	if (A == 1)
		result = 1;
	else if (A == 8)
		result = -1;

	for (int i = 2;i <= 8;i++) {
		cin >> A;
		if (!(A == i && result == 1) && !(A == 9 - i && result == -1))
			result = 0;
	}
	cout << (result >= 0 ? result <= 0 ? "mixed" : "ascending" : "descending");
}
