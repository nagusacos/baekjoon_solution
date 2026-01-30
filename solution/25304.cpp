#include <iostream>
using namespace std;

int main() {
	int X, N;
	cin >> X >> N;
	int sum = 0;
	for (int i = 0;i < N;i++) {
		int A, B;
		cin >> A >> B;
		sum += A * B;
	}
	cout << (X == sum ? "Yes" : "No");
}