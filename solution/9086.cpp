#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	string A;
	for (int i = 0;i < N;i++) {
		cin >> A;
		cout << A.front() << A.back() << "\n";
	}
}