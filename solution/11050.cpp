#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	int A = 1, B = 1;
	for (int i = N - K + 1;i <= N;i++)
		A *= i;
	for (int i = 1;i <= K;i++)
		B *= i;
	cout << A / B;
}