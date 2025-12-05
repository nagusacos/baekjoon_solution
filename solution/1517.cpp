#include <iostream>
using namespace std;

int A[500001]{};
int temp[500001]{};

long long f(int i,int j) {
	if (j - i <= 0)
		return 0;
	
	int m = (i + j) / 2;
	long long sum = f(i, m) + f(m + 1, j);

	long long  a = i, b = m + 1, k = i;

	for (int k = i;k <= j;k++)//copy
		temp[k] = A[k];

	for (;a <= m && b <= j;) {
		if (temp[b] < temp[a]) {
			sum += (b - k);
			A[k++] = temp[b++];
		}
		else {
			A[k++] = temp[a++];
		}
	}
	for (;b <= j;) {
		A[k++] = temp[b++];
	}
	for (;a <= m;) {
		A[k++] = temp[a++];
	}
	return sum;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	cout << f(0, N - 1);
}