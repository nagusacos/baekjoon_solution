#include <iostream>
#include <algorithm>
using namespace std;

bool order(const int* a,const int* b) {
	if (a[0] == b[0])
		return a[1] < b[1];
	return a[0] < b[0];
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int* A[100001];
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		A[i] = new int[2];
		cin >> A[i][0] >> A[i][1];
	}
	sort(A, A + N, order);
	for (int i = 0;i < N;i++)
		cout << A[i][0] << " " << A[i][1] << "\n";
}