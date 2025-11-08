#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int temp, max = 0, index = 0;
	int i = 1;
	for (;;i++) {
		cin >> temp;
		if (cin.eof())
			break;
		if (temp > max) {
			max = temp;
			index = i;
		}
	}
	cout << max << "\n" << index;
}