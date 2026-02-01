#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int D[100] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
	string str;
	cin >> str;
	int sum = 0;
	for (const char& c : str) {
		int num = D[(int)c - 65];
		sum += num;
	}
	cout << sum;
}