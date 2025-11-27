#include <iostream>
using namespace std;

int A[21];
bool S[2000001]{};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
		cin >> A[i];

	unsigned int U = ((1 << N) + ~0);
	for (unsigned int subset = U;subset >= (1 << N - 1);subset = ((subset + ~0) & U)) {
		int a = 0, b = 0;
		for (int i = 0;i < N;i++) {
			if (subset & (1 << i))
				a += A[i];
			else
				b += A[i];
		}
		S[a] = true;
		S[b] = true;
	}

	for (int i = 1;;i++) {
		if (!S[i]) {
			cout << i;
			break;
		}
	}
}