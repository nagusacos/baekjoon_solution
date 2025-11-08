#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	for (;;) {
		int A, B, C;
		cin >> A >> B >> C;
		if (A == B && B == C && C == 0)
			break;
		if (A > B) {
			if (A > C)//A--
				cout << (A * A == B * B + C * C ? "right\n" : "wrong\n");
			else//CAB
				cout << (C * C == A * A + B * B ? "right\n" : "wrong\n");
		}
		else {
			if (B > C)//B--
				cout << (B * B == A * A + C * C ? "right\n" : "wrong\n");
			else//CBA
				cout << (C * C == B * B + A * A ? "right\n" : "wrong\n");
		}
	}
}