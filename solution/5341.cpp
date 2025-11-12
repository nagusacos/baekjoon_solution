#include <iostream>
using namespace std;

int main() {
	for (;;) {
		int A;
		cin >> A;
		if (A == 0)
			break;
		cout << A * (A + 1) / 2 << "\n";
	}
}