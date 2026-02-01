#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int G[100] = { 1,1,2,2,2,8 };
	for (int i = 0;i < 6;i++) {
		int tmp;
		cin >> tmp;
		cout << G[i] - tmp << " ";
	}
}