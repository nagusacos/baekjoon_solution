#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N - i;j++)
			cout << " ";
		for (int j = N - i + 1;j <= N + i - 1;j++)
			cout << "*";
		for (int j = N + i;j <= N;j++)
			cout << " ";
		cout << "\n";
	}
}