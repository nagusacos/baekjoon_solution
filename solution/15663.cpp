#include <iostream>
#include <algorithm>
using namespace std;

int R[10]{};
int seq[10]{};
int check[10]{};
int N, M;

void f(int m) {
	if (m <= 0) {
		cout << R[seq[M]];
		for (int i = M - 1;i >= 1;i--)
			cout << " " << R[seq[i]];
		cout << "\n";
		return;
	}
	for (int i = 0;i < N;i++) {
		if (!check[i]) {
			check[i] = true;
			seq[m] = i;
			f(m - 1);
			check[i] = false;
			for (;i < N;i++)
				if (R[i] != R[i + 1])
					break;
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0;i < N;i++)
		cin >> R[i];
	sort(R, R + N);
	R[N] = -1;
	f(M);
}