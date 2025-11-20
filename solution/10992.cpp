#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int j = 1;j <= N - 1;j++)
		cout << " ";
	if (N != 1)
		cout << "*\n";
	for (int i = 2;i <= N-1;i++) {
		for (int j = 1;j <= N - i;j++)
			cout << " ";
		cout << "*";
		for (int j = N - i + 2;j <= N + i - 2;j++)
			cout << " ";
		cout << "*\n";
	}
	for (int j = 1;j <= 2 * N - 1;j++)
		cout << "*";
	cout << "\n";
}