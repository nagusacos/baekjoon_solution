#include <iostream>
using namespace std;
typedef long long integer;

void debug(integer** system, int N, int M) {
	cout << "debug===\n";
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++)
			cout << system[i][j] << " ";
		cout << " : " << system[i][M] << "\n";
	}
}

integer gcd(integer a, integer b) {
	if (a > b)swap(a, b);//a<=b
	for (;a > 0;a %= b)swap(a, b);
	return b;
}

void change(integer** system, int M, int a, int b) {
	for (int j = 0;j < M + 1;j++)
		swap(system[a][j], system[b][j]);
}

void del(integer** system, int M, int from, int to, int k) {
	integer a = system[from][k];
	integer b = system[to][k];
	integer d = gcd(abs(a), abs(b));
	a /= d;
	b /= d;
	for (int j = 0;j < M + 1;j++)
		system[to][j] = system[to][j] * a - system[from][j] * b;
}

int solve(integer** system, int N, int M) {
	for (int i = 0;i < N;i++) {
		if (system[i][i] == 0) {
			for (int k = i + 1;k < N;k++) {
				if (system[k][i] != 0) {
					change(system, M, i, k);
					break;
				}
			}
		}
		for (int j = i + 1;j < N;j++) {
			del(system, M, i, j, i);
		}
	}
	for (int i = N - 1;i>=0;i--) {
		system[i][M] /= system[i][i];
		system[i][i] = 1;
		for (int j = i - 1;j >= 0;j--) {
			del(system, M, i, j, i);
		}
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int N;
	cin >> N;

	integer** system = new integer * [N + 1];
	for (int i = 0;i < N;i++) {
		system[i] = new integer[N + 2];
		for (int j = 0;j < N + 1;j++)
			cin >> system[i][j];
	}

	solve(system, N, N);

	for (int i = 0;i < N;i++)
		cout << system[i][N] << " ";
}