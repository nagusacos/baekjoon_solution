#include <iostream>
#include <algorithm>
using namespace std;

long long int A[1000001];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long int N, M;
	cin >> N >> M;
	for (int i = 0;i < N;i++)
		cin >> A[i];
	sort(A, A + N);

	long long int low = 0, up = A[N - 1];
	for (;low < up;) {
		long long int  mid = (low + up) / 2;
		long long int sum = 0;
		for (int i = N - 1;i >= 0;i--) {
			if (A[i] > mid)
				sum += A[i] - mid;
			else
				break;
		}
			
		if (sum >= M)
			low = mid + 1;
		else
			up = mid;
	}

	low--;
	long long int low_sum = 0;
	for (int i = N - 1;i >= 0;i--) {
		if (A[i] > low)
			low_sum += A[i] - low;
		else
			break;
	}
	long long int up_sum = 0;
	for (int i = N - 1;i >= 0;i--) {
		if (A[i] > up)
			up_sum += A[i] - up;
		else
			break;
	}


	cout << (M <= low_sum ? low : up);
}