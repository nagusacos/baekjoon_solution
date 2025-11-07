#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	bool A[31]{ false, };
	int temp;
	for (int i = 0;i < 28;i++) {
		cin >> temp;
		A[temp] = true;
	}
	for (int i = 1;i <= 30;i++)
		if (!A[i])
			cout << i << "\n";
}