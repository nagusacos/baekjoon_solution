#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int k = 0;k < N;k++)
			cout << " ";
		for (int k = 0;k < N - 1 - i;k++)
			cout << " ";
		cout << "*";
		for (int k = 0;k < N;k++)
			cout << " ";
		cout << "*";
		for (int k = 0;k < 2 * i + 1;k++)
			cout << " ";
		cout << "*";
		for (int k = 0;k < N - 1 - i;k++)
			cout << " ";
		cout << "\n";
	}
	for (int i = 0;i < N;i++) {
		for (int k = 0;k < N - 1 - i;k++)
			cout << " ";
		cout << "*";
		for (int k = 0;k < N;k++)
			cout << " ";
		for (int k = 0;k < 2 * i + 1;k++)
			cout << " ";
		cout << "*";
		for (int k = 0;k < 2 * (N - i) - 1;k++)
			cout << " ";
		cout << "*";
		for (int k = 0;k < i;k++)
			cout << " ";
		cout << "\n";
	}
}