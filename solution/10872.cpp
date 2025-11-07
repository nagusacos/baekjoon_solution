#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int k = 1;
	for (int i = 1;i <= N;i++)
		k *= i;
	cout << k;
}