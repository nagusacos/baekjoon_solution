#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	string temp;
	bool result;
	int count;
	for (int i = 0;i < N;i++) {
		cin >> temp;
		result = true;
		count = 0;
		for (const char& c : temp) {
			if (c == '(')
				count++;
			else {
				count--;
				if (count<0)
					break;
			}
		}
		cout << (count == 0 ? "YES\n" : "NO\n");
	}
}