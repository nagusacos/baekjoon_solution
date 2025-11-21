#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int sum = 0;
	for (int i = 0;i < 5;i++) {
		int temp;
		cin >> temp;
		sum += (temp >= 40 ? temp : 40);
	}
	cout << sum / 5;
}