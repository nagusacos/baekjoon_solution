#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string A;
	int N;
	cin >> A >> N;
	cout << A[N - 1];
}