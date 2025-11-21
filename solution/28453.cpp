#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int temp;
	cin >> temp;
	cout << (temp >= 300 ? 1 : temp >= 275 ? 2 : temp >= 250 ? 3 : 4);
	for (int i = 1;i < N;i++) {
		int temp;
		cin >> temp;
		cout << " " << (temp >= 300 ? 1 : temp >= 275 ? 2 : temp >= 250 ? 3 : 4);
	}
}
