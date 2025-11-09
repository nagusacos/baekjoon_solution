#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int A[101];
	for (int i = 0;i < N;i++)
		cin >> A[i];

	int max = 0;
	for (int i = 0;i < N;i++)
		for (int j = N - 1;j > i;j--)
			for (int k = i + 1;k < j;k++)
				if (A[i] + A[j] + A[k] <= M && A[i] + A[j] + A[k] > max)
					max = A[i] + A[j] + A[k];

	cout << max;
}