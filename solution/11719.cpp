#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	for (;;) {
		string temp;
		getline(cin, temp);
		if (cin.eof())
			break;
		cout << temp << "\n";
	}
}