#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string S;
	cin >> S;
	int A[26]{ 0, };
	for (int i = 0;i < S.size();i++)
		if (A[(int)S[i] - 97] == 0)
			A[(int)S[i] - 97] = i + 1;

	cout << A[0] - 1;
	for (int i = 1;i < 26;i++)
		cout << " " << A[i] - 1;
}