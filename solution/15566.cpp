#include <iostream>
#include <algorithm>
using namespace std;

int R[10]{};
int seq[10]{};
int N = 0, M;

void f(int bound, int m) {
	if (m <= 0) {
		cout << R[seq[M]];
		for (int i = M - 1;i >= 1;i--)
			cout << " " << R[seq[i]];
		cout << "\n";
		return;
	}
	for (int i = bound;i < N;i++) {
		seq[m] = i;
		f(i, m - 1);
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int num = 0;
	cin >> num >> M;
	int temp[10];
	for (int i = 0;i < num;i++)
		cin >> temp[i];
	sort(temp, temp + num);
	
	R[N++] = temp[0];
	for (int i = 1;i < num;i++)
		if (temp[i] != R[N - 1])
			R[N++] = temp[i];
		
	f(0, M);
}