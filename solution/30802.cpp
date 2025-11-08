#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, T, P;
	int A[6];
	cin >> N;
	for (int i = 0;i < 6;i++)
		cin >> A[i];
	cin >> T >> P;

	int sum_T = 0, B = 0;
	for (int i = 0;i < 6;i++) {
		sum_T += (A[i] + T - 1) / T;
		B += A[i];
	}
	cout << sum_T << "\n" << B / P << " " << B % P;
}
