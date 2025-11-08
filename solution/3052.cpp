#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int temp;
	int A[42]{ 0, };
	for (int i = 0;i < 10;i++) {
		cin >> temp;
		A[temp % 42]++;
	}
	int sum = 0;
	for (int i = 0;i < 42;i++) {
		if (A[i] > 0)
			sum++;
	}
	cout << sum;
}