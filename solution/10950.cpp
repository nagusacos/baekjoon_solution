#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, A, B;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> A >> B;
		cout << A + B << "\n";
	}
}