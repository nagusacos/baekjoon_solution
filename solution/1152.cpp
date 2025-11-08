#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string A;
	int sum = 0;
	for (;;) {
		cin >> A;
		if (cin.eof())
			break;
		sum++;
	}
	cout << sum;
}