#include <iostream>
using namespace std;

int N, M;
int A[5][5]{};

bool is_vertical(unsigned int B, int i, int j) {
	return (bool)(B & (1 << (i * M + j)));
}
int calculate(unsigned int subset) {
	int sum = 0;
	for (int i = 0;i < N;i++) {//horizion
		int digit = 1;
		int j = M - 1;
		for (;j >= 0;j--) {
			if (!is_vertical(subset, i, j)) {
				sum += A[i][j] * digit;
				digit *= 10;
			}
			else
				digit = 1;
		}
	}
	for (int j = 0;j < M;j++) {//vertial
		int digit = 1;
		int i = N - 1;
		for (;i >= 0;i--) {
			if (is_vertical(subset, i, j)) {
				sum += A[i][j] * digit;
				digit *= 10;
			}
			else
				digit = 1;
		}
	}
	return sum;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			char temp;
			cin >> temp;
			A[i][j] = (int)(temp - '0');
		}
	}

	unsigned int U = ((1 << (N * M)) + ~0);//4*4
	//0 : horizion
	//1 : vertial
	//2^16
	int maximum = 0;
	for (unsigned int subset = U;subset;subset = ((subset + ~0) & U)) {
		maximum = max(maximum, calculate(subset));
	}
	maximum = max(maximum, calculate(0));

	cout << maximum;
}