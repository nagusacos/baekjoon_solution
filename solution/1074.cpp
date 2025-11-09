#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	unsigned int N, R, C;
	cin >> N >> R >> C;

	unsigned int sum = 0;

	unsigned int M[2][2];
	M[0][0] = 0;
	M[0][1] = 1;
	M[1][0] = 2;
	M[1][1] = 3;
	
	for (unsigned int i = 0;i < N;i++) {
		sum += (M[(R & 1)][(C & 1)] << (i << 1));// [(R mod 2) + 2*(C mod 2)] * 2^(2*i)
		R >>= 1;
		C >>= 1;
	}
	cout << sum;
}