#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	bool A[1001]{ true,true, };
	for (int i = 3;i <= 33;i += 2)
		for (int k = i + i;k < 1001;k += i)
			A[k] = true;

	int N;
	cin >> N;
	int temp, sum = 0;
	for (int i = 0;i < N;i++) {
		cin >> temp;
		if (temp == 2 || (temp & 1 && !A[temp]))
			sum++;
			
	}
	cout << sum;
}