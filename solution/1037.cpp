#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int N;
	cin>>N;
	int M = 0, m = 1000001;
	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		if (M < temp)
			M = temp;
		if (m > temp)
			m = temp;
	}
	cout << M * m;
}