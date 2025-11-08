#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int temp;
	string str;
	for (int i = 0;i < N;i++) {
		cin >> temp >> str;
		for (const auto& c : str)
			for (int i = 0;i < temp;i++)
				cout << c;
		cout << "\n";
	}
}