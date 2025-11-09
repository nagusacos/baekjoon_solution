#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool order(const string& a, const string& b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	return a < b;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	string A[20001];
	for (int i = 0;i < N;i++)
		cin >> A[i];
	sort(A, A + N, order);
	string pre = A[0];
	cout << A[0] << "\n";
	for (int i = 1;i < N;i++) {
		if (pre != A[i]) {
			pre = A[i];
			cout << A[i] << "\n";
		}
	}
}