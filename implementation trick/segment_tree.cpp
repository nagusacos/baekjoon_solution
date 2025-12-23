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
	void update(int idx, int k) { update(idx, k, 0, N - 1, 1); }
	void update(int idx, int k,int i, int j,  int n) {
		if (i >= j) {
			seg[n] = k;
			return;
		}
		int m = (i + j) / 2;
		int l = 2 * n, r = 2 * n + 1;
		if (idx <= m)
			update(idx, k, i, m, l);
		else
			update(idx, k, m + 1, j, r);
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
	void print() {//debug
		for (int i = 1;i < 4 * N;i <<= 1) {
			for (int j = 0;j < i && i + j < 4*N;j++) {
				cout << seg[i + j] << " ";
			}
			cout << "\n";
		}
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
	segtree max_seg(N, maximum);
	segtree min_seg(N, minimum);
	max_seg.init(A);
	min_seg.init(A);
	max_seg.print();
	min_seg.print();
}
