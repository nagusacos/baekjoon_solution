#include <iostream>
using namespace std;

int A[501]{};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		int from, to;
		cin >> from >> to;
		A[from] = to;
	}

	int bound[500]{};
	int len = 1;
	for (int i = 1;i <= 500;i++) {
		if (A[i] == 0)
			continue;

		int a = 0, b = len - 1;
		for (;a<b;) {
			int m = (a + b) / 2;
			if (bound[m] < A[i])
				a = m + 1;
			else
				b = m;
		}

		if (a == len - 1 && bound[a] < A[i])
			bound[len++] = A[i];

		else if (A[i]< bound[a])
			bound[a] = A[i];
	}
	cout << N - (len - 1);
}