#include <iostream>
using namespace std;

int A[1000001];
int bound[1000001]{ -1000000001, };
int len = 1;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	for (int i = 1;i <= N;i++)
		cin >> A[i];

	for (int i = 1;i <= N;i++) {
		int l = 0;
		int r = len - 1;
		for (;l < r;) {
			int m = (l + r) / 2;
			if (bound[m] < A[i])
				l = m + 1;
			else
				r = m;
		}

		if (r == len - 1 && bound[r] < A[i]) {
			len++;
			r++;
			bound[r] = A[i];
		}

		if (A[i] < bound[r])
			bound[r] = A[i];
	}
	cout << len - 1;
}