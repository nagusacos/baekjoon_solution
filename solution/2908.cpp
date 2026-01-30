#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	string A, B;
	cin >> A >> B;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	int a = stoi(A);
	int b = stoi(B);
	cout << (a > b ? a : b);
}