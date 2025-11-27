#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, S;
	cin >> N >> S;
	int A[21];
	for (int i = 0;i < N;i++)
		cin >> A[i];

	unsigned int B = ((1 << N) + ~0);
	int count = 0;
	for (unsigned int subset = B;subset;subset = ((subset + ~0) & B)) {
		int sum = 0;
		for (int i = 0;i < N;i++) {
			if (subset & (1 << i))
				sum += A[i];
		}
		if (sum == S)
			count++;
	}
	cout << count;
}