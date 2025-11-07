#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, V, count = 0;
	int A[101];

	cin >> N;
	for (int i = 0;i < N;i++)
		cin >> A[i];

	cin >> V;
	for (int i = 0;i < N;i++)
		if (A[i] == V)
			count++;

	cout << count;
}