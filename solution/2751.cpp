#include <iostream>
#include <algorithm>
using namespace std;

int A[1000001];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
		cin >> A[i];
	sort(A, A + N);
	for (int i = 0;i < N;i++)
		cout << A[i] << "\n";
}