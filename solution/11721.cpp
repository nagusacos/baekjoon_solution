#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	for (;;) {
		string temp;
		cin.width(10);
		cin >> temp;
		if (cin.eof())
			break;
		cout << temp << "\n";
	}
}
