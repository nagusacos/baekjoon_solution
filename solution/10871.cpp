#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, X;
	int A[10001];
	cin >> N >> X;
	for (int i = 0;i < N-1;i++) {
		cin >> A[i];
		if (A[i] < X)
			cout << A[i] << " ";
	}
	cin >> A[N-1];
	if (A[N - 1] < X)
		cout << A[N - 1];
}

//not using array

/*
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, X;
	int A;
	cin >> N >> X;
	for (int i = 0;i < N-1;i++) {
		cin >> A;
		if (A < X)
			cout << A << " ";
	}
	cin >> A;
	if (A < X)
		cout << A;
}
*/