#include <iostream>
#include <algorithm>
using namespace std;

struct person {
	int old;
	int index;
	string name;
};

person A[100001];

bool order(const person& a,const person& b) {
	if (a.old == b.old)
		return a.index < b.index;
	return a.old < b.old;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> A[i].old >> A[i].name;
		A[i].index = i;
	}
		
	sort(A, A + N, order);
	for (int i = 0;i < N;i++)
		cout << A[i].old << " " << A[i].name << "\n";
}