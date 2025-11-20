#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	cin.ignore();
	for (;T-- > 0;) {
		int A, B;
		string temp;
		getline(cin, temp, ',');
		A = stoi(temp);
		getline(cin, temp);
		B = stoi(temp);
		cout << A + B << "\n";
	}
}