#include <iostream>
using namespace std;

#define digit 1000000000

void f(int a, int b, int c, int n) {
	if (n <= 1) {
		cout << a << " " << c << "\n";
		return;
	}
		
	f(a, c, b, n - 1);
	cout << a << " " << c << "\n";
	f(b, a, c, n - 1);
}

void double_up(int A[10]) {
	int D[10]{ 0, };;
	for (int i = 0;i < 9;i++) {
		if (A[i] <= 0)
			break;

		A[i] <<= 1;
		if (A[i] >= digit) {
			D[i + 1] = A[i] / digit;
			A[i] %= digit;
		}
	}
	for (int i = 0;i < 9;i++)
		A[i] += D[i];
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int A[10]{ 1, };
	for (int i = 0;i < N;i++)
		double_up(A);
	A[0]--;

	int i = 9;

	for (;i >= 0;i--)
		if (A[i] > 0)
			break;

	cout << A[i--];
	cout.fill('0');

	for (;i >= 0;i--) {
		cout.width(9);
		cout << A[i];
	}
	cout << "\n";
		
	if(N<=20)
		f(1, 2, 3, N);
}