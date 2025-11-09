#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	for (;;) {
		string str;
		cin >> str;
		if (str == "0")
			break;

		int len = str.size();
		bool result = true;
		for (int i = 0;i+i<=len;i++) {
			if (str[i] != str[len - 1 - i]) {
				result = false;
				break;
			}
		}
		cout << (result ? "yes\n" : "no\n");
	}
}