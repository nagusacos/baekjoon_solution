#include <iostream>
using namespace std;

int P[100002];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	P[0] = 0;
	for (int i = 1;i <= N;i++) {
		cin >> P[i];
		P[i] += P[i - 1];
	}
	for (;M-- > 0;) {
		int i, j;
		cin >> i >> j;
		cout << P[j] - P[i - 1] << "\n";
	}
}