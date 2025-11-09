#include <iostream>
using namespace std;

#define d(k,inter) (inter - k < k ? inter - k : k)

int A[51][51];

int delta_i(int i, int j) {
	int delta = 0;
	for (int k = 0;k < 8;k++)
		delta += A[i - 7 + k][j] - A[i - 7 + k][j - 8];
	return delta;
}
int delta_j(int i, int j) {
	int delta = 0;
	for (int k = 0;k < 8;k++)
		delta += A[i][j - 7 + k] - A[i - 8][j - 7 + k];
	return delta;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			char temp;
			cin >> temp;
			A[i][j] = ((temp == 'W') == ((i + j) & 1));
		}
	}

	int size = 64;
	int sum = 0, min = 1000, pre_sum;

	for (int i = 0;i < 8;i++)
		for (int j = 0;j < 8;j++)
			sum += A[i][j];
	min = d(sum, size);
	pre_sum = sum;

	for (int j = 8;j < M;j++) {
		sum += delta_i(7, j);
		min = d(sum, size) < min ? d(sum, size) : min;
	}

	for (int i = 8;i < N;i++) {
		sum = pre_sum;

		sum += delta_j(i, 7);
		min = d(sum, size) < min ? d(sum, size) : min;

		pre_sum = sum;

		for (int j = 8;j < M;j++) {
			sum += delta_i(i, j);
			min = d(sum, size) < min ? d(sum, size) : min;
		}
	}
	cout << min;
}