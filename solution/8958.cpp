#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		string str;
		cin >> str;

		int sum = 0;
		int score = 0;
		for (const char& c : str) {
			if (c == 'O')
				score++;
			else
				score = 0;
			sum += score;
		}
		cout << sum << "\n";
	}
}