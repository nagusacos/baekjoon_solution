#include <iostream>
using namespace std;

int seq[10];
bool check[10];
int N, M;

void f(int bound, int m) {
	if (m <= 0) {
		cout << seq[M];
		for (int i = M - 1;i >= 1;i--)
			cout << " " << seq[i];
		cout << "\n";
		return;
	}
	for (int i = bound + 1;i <= N;i++) {
		if (!check[i]) {
			check[i] = true;
			seq[m] = i;
			f(i, m - 1);
			check[i] = false;
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	f(0, M);
}
