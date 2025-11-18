#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;
	int value = 0;
	for (char c : str) {
		if (c == '7') {
			value = 2;
			break;
		}
	}
	value += (stoi(str) % 7 == 0);
	cout << value;
}