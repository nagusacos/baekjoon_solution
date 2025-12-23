#include <iostream>
using namespace std;

#define MAX 1000000001
#define MIN -1000000001

int* A = new int[4000001];

class segtree {
private:
	int N;
	int (*f)(const int, const int);
	int* seg;
public:
	segtree(int size, int (*operation)(int, int)) :N(size), f(operation) { seg = new int[4 * N] {0, }; }
	void init(int* arr) { init(arr, 0, N - 1, 1); }
	void init(int* arr, int i, int j, int n) {
		if (i >= j) {
			seg[n] = arr[i];
			return;
		}
		int m = (i + j) / 2;
		int l = 2 * n, r = 2 * n + 1;
		init(arr, i, m, l);
		init(arr, m + 1, j, r);
		seg[n] = f(seg[l], seg[r]);
	}
	int interval(int a, int b, int ground = 0) { return interval(a, b, ground, 0, N - 1, 1); }
	int interval(int a, int b,int ground, int i, int j, int n) {
		if (j < a || b < i)
			return ground;
		else if (a <= i && j <= b)
			return seg[n];
		int m = (i + j) / 2;
		int l = 2 * n, r = 2 * n + 1;
		int v1 = interval(a, b, ground, i, m, l);
		int v2 = interval(a, b, ground, m + 1, j, r);
		return f(v1, v2);
	}
};
int maximum(const int a,const int b) {
	return max(a, b);
}
int minimum(const int a, const int b) {
	return min(a, b);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	segtree min_seg(N, minimum);
	segtree max_seg(N, maximum);
	min_seg.init(A);
	max_seg.init(A);
	
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << min_seg.interval(a, b, MAX) << " " << max_seg.interval(a, b, MIN) << "\n";
	}
}