#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A[101][101];
	int B[101][101];
	int N, M;
	cin >> N >> M;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			cin >> A[i][j];

	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			cin >> B[i][j];

	for (int i = 0;i < N;i++) {
		cout << A[i][0] + B[i][0];
		for (int j = 1;j < M;j++)
			cout << " " << A[i][j] + B[i][j];
		cout << "\n";
	}	
}