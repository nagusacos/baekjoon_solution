


//base code

/*
#include <iostream>
using namespace std;

int N;

void foward_fill(bool** F, int i, int j) {
	for (int k = 1;i + k < N && j + k < N;k++)
		F[i + k][j + k] = true;
	for (int k = 1;i + k < N && 0 <= j - k;k++)
		F[i + k][j - k] = true;
	for (int k = 1;k < N;k++)
		F[k][j] = true;
}

bool** copy_board(bool** from) {
	bool** F = new bool* [N];
	for (int i = 0;i < N;i++) {
		F[i] = new bool[N];
		for (int j = 0;j < N;j++)
			F[i][j] = from[i][j];
	}
	return F;
}

void del_board(bool** F) {
	for (int i = 0;i < N;i++)
		delete[] F[i];
	delete[] F;
}

int f(bool** F, int i) {
	if (i == N)//to the end
		return 1;
	int sum = 0;
	for (int j = 0;j < N;j++) {
		if (!F[i][j]) {
			bool** temp = copy_board(F);
			foward_fill(temp, i, j);
			sum += f(temp, i + 1);
			del_board(temp);
		}
	}
	return sum;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N;

	bool** A = new bool* [N];
	for (int i = 0;i < N;i++)
		A[i] = new bool[N] {0, };
	
	cout << f(A,0);
}
*/