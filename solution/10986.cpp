#include <iostream>
using namespace std;

long long R[1001]{};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		sum += temp;
		sum %= M;
		R[sum]++;
	}

	long long comb = R[0];
	for (int i = 0; i < M; i++)
		comb += (R[i] * (R[i] - 1)) / 2;
	cout << comb;
}