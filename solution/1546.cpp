#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int temp, max = 0, sum = 0;

	for (int i = 0;i < N;i++) {
		cin >> temp;
		sum += temp;
		if (temp > max)
			max = temp;
	}
	cout << fixed;
	cout.precision(3);
	cout << (100 * sum) / (float)(N * max);
}