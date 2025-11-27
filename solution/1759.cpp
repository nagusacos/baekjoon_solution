#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
char A[20];
char seq[20];
int a = 0;
int b = 0;

void f(int idx,int n) {
	if (n <= 0) {
		if (a>=1&&b>=2) {
			for (int i = N;i >= 1;i--)
				cout << seq[i];
			cout << "\n";
		}
		return;
	}
	for (int i = idx;i < M;i++) {
		seq[n] = A[i];
		if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u') {
			a++;
			f(i + 1, n - 1);
			a--;
		}
		else {
			b++;
			f(i + 1, n - 1);
			b--;
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	
	for (int i = 0;i < M;i++)
		cin >> A[i];

	sort(A, A + M);
	f(0, N);
}