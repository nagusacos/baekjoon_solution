#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string A;
	cin >> A;
	int gap = 'a' - 'A';
	for (int i = 0;i < A.size();i++)
		cout << (char)(A[i] < 'a' ? A[i] + gap : A[i] - gap);
}