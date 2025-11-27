#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int sum = 0;
	int A[10];
	for (int i = 0;i < 9;i++) {
		cin >> A[i];
		sum += A[i];
	}
	sort(A, A + 9);
	for (int i = 0;i < 8;i++) {
		for (int j = i + 1;j < 9;j++) {
			if (sum - A[i] - A[j] == 100) {
				for (int k = 0;k < 9;k++) {
					if (k != i && k != j) {
						cout << A[k] << "\n";
					}
				}
				return 0;
			}
		}
	}
}