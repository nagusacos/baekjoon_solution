#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef struct name_val {
	int id;
	int val;
} name_val;

inline bool operator<(const name_val& a, const name_val& b) {
	return a.val < b.val;
}

name_val X[2000001];
set<int> S;

int main() {
	int N;
	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> X[(i << 1)].val >> X[(i << 1) + 1].val;
		X[(i << 1)].id = i;
		X[(i << 1) + 1].id = i;
	}

	sort(X, X + (N + N));

	int sum = 0;
	int pre = X[0].val;
	for (int i = 0;i < N + N;i++) {
		if (S.empty()) {
			S.insert(X[i].id);
			pre = X[i].val;
		}
		else {
			auto f = S.find(X[i].id);
			if (f != S.end()) {
				S.erase(f);
				if (S.empty())
					sum += X[i].val - pre;	
			}
			else {
				S.insert(X[i].id);
			}
		}
	}
	cout << sum;
}