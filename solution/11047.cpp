#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	int A[11];
	for (int i = 0;i < N;i++)
		cin >> A[i];
	int sum = 0;
	for (int i = N - 1;i >= 0;i--) {
		sum += K / A[i];
		K %= A[i];
	}
	cout << sum;
}