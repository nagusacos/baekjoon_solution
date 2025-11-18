#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	for (;;) {
		getline(cin, str);
		if (str == "EOI")
			break;

		bool check = false;
		for (int i = 0;i < str.size();i++) {
			if (str[i] == 'n' || str[i] == 'N') {
				if (i + 3 < str.size()) {
					if ((str[i+1] == 'e' || str[i+1] == 'E') &&
						(str[i+2] == 'm' || str[i+2] == 'M') &&
						(str[i+3] == 'o' || str[i+3] == 'O')) {
						check = true;
						break;
					}
					i += 3;
				}
			}
		}
		cout << (check ? "Found\n" : "Missing\n");
	}
}