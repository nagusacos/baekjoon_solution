#include <iostream>
using namespace std;

int bound[100001]{};
int len = 1;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;

		int a = 0, b = len - 1;
		for (;a < b;) {
			int m = (a + b) / 2;
			if (bound[m] < temp)
				a = m + 1;
			else
				b = m;
		}

		if (a == len - 1 && bound[a] < temp)
			bound[len++] = temp;

		else if (temp < bound[a])
			bound[a] = temp;
	}
	cout << N - (len - 1);
}