#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string A_str, B_str;
	cin >> A_str >> B_str;
	int A = stoi(A_str);
	int B = stoi(B_str);
	int S = stoi(A_str + B_str);
	int C;
	cin >> C;
	cout << A + B - C << "\n" << S - C;
}