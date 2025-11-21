#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (;T-- > 0;) {
		string A, B;
		cin >> A >> B;
		int sum = 0;
		for (int i = 0;i < A.size();i++)
			if (A[i] != B[i])
				sum++;
		cout << "Hamming distance is " << sum << ".\n";
	}
}
