#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A, B, C;
	cin >> A >> B >> C;
	string S = to_string(A * B * C);

	int R[10]{ 0, };

	for (const char& s : S)
		R[(int)s - 48]++;
	for (int i = 0;i < 10;i++)
		cout << R[i] << "\n";
}